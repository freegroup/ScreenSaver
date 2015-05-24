//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// �  1999 FreeGroup www.FreeGroup.de
//
// File    : NumEdit.cpp 
// Created : 05/28/1999 03:18:34 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "NumEdit.h"
#include "Float.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumEdit

IMPLEMENT_DYNAMIC(CNumEdit, CEdit)

CNumEdit::CNumEdit()
{
	m_NumberOfNumberAfterPoint = 0;
	m_Verbose = FALSE;
	m_MinValue = -FLT_MAX;
	m_MaxValue = FLT_MAX;
	m_Delta = FLT_ROUNDS;
}

CNumEdit::~CNumEdit()
{
}


BEGIN_MESSAGE_MAP(CNumEdit, CEdit)
	//{{AFX_MSG_MAP(CNumEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumEdit message handlers

float CNumEdit::GetValue() const
{
	float f = 0.0f;
	if (IsValid() == VALID)
	{
		CString str;
		GetWindowText(str);
		sscanf(str, "%f", &f);
	}
	return f;
}

BOOL CNumEdit::SetValue(float val)
{
	if (val > m_MaxValue || val < m_MinValue) return FALSE;
	CString str, s;
	str.Format(ConstructFormat(s, val), val);
	SetWindowText(str);
	return TRUE;
}

int CNumEdit::IsValid() const
{
	CString str;
	GetWindowText(str);
	int res = VALID;
	float f;
	char lp[10];
	if (sscanf(str, "%f%s", &f, lp) != 1) res = INVALID_CHAR;
	if (f > m_MaxValue || f < m_MinValue) res = OUT_OF_RANGE;
	if (m_Verbose && res != VALID)
	{
		str.Empty();
		if (res & OUT_OF_RANGE) str += _T("Given value is out of range.\n");
		if (res & INVALID_CHAR) str += _T("Characters must be a number.\n");
		AfxMessageBox(str, MB_OK | MB_ICONSTOP);
	}
	return res;
}

int CNumEdit::IsValid(const CString &str) const
{
	int res = VALID;
	float f;
	char lp[10];
	if (sscanf(str, "%f%s", &f, lp) != 1) res = INVALID_CHAR;
	if (f > m_MaxValue && f < m_MinValue) res = OUT_OF_RANGE;
	if (m_Verbose && res != VALID)
	{
		CString msg;
		msg.Empty();
		if (res & OUT_OF_RANGE) msg += _T("Given value is out of range.\n");
		if (res & INVALID_CHAR) msg += _T("Characters must be a number.\n");
		AfxMessageBox(str, MB_OK | MB_ICONSTOP);
	}
	return res;
}

void CNumEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == ' ') return;
	float oldValue;
	oldValue = GetValue();
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	if (IsValid() != VALID)
	{
		SetValue(oldValue);
		SetSel(0, -1);
		MSG msg;
		while (::PeekMessage(&msg, m_hWnd, WM_CHAR, WM_CHAR, PM_REMOVE));
	} else
	{
		CString s;
		ConstructFormat(s, GetValue());
	}
}

BOOL CNumEdit::Verbose() const
{
	return m_Verbose;
}

void CNumEdit::Verbose(BOOL v)
{
	m_Verbose = v;
}

void CNumEdit::SetRange(float min, float max)
{
	m_MinValue = min;
	m_MaxValue = max;
}

void CNumEdit::GetRange(float & min, float & max) const
{
	min = m_MinValue;
	max = m_MaxValue;
}

void CNumEdit::SetDelta(float delta)
{
	m_Delta = delta;
}

float CNumEdit::GetDelta()
{
	return m_Delta;
}

void CNumEdit::ChangeAmount(int step)
{
	float f = GetValue() + step * m_Delta;
	if (f > m_MaxValue) f = m_MaxValue;
	else if (f < m_MinValue) f = m_MinValue;
	SetValue(f);
}

CString& CNumEdit::ConstructFormat(CString &str, float num)
{
	str.Format("%G", num);
	int n = str.Find('.');
	if (n >= 0)
	{
		n = str.GetLength() - n - 1;
		if (n > m_NumberOfNumberAfterPoint) m_NumberOfNumberAfterPoint = n;
	}
	str.Format("%%.%df", m_NumberOfNumberAfterPoint);
	return str;
}
