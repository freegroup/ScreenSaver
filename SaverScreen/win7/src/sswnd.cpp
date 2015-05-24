//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : sswnd.cpp 
// Created : 05/28/1999 03:19:23 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ssbase.h"


/////////////////////////////////////////////////////////////////////////////
// CSmallWnd
BEGIN_MESSAGE_MAP(CSmallWnd, CWnd)
	//{{AFX_MSG_MAP(CSmallWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//----------------------------------------------------------------------------
CSmallWnd::CSmallWnd(){
//----------------------------------------------------------------------------
	m_uTimeTick = 100;
	m_brBk=NULL;
}


//----------------------------------------------------------------------------
CSmallWnd::~CSmallWnd(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
BOOL CSmallWnd::CreateAsShow(CWnd* pParent){
//----------------------------------------------------------------------------
	LPCSTR lpszClassName;
	lpszClassName = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,NULL,m_brBk);
	CRect rect;
	pParent->GetClientRect(rect);
	return CreateEx(0, 
					lpszClassName, 
					_T(""), 
					WS_CHILD|WS_VISIBLE, 
					rect.left, 
					rect.top, 
					rect.right - rect.left, 
					rect.bottom - rect.top, 
					pParent->GetSafeHwnd(), 
					NULL, 
					NULL );
}

//----------------------------------------------------------------------------
void CSmallWnd::OnTimer(UINT nIDEvent){
//----------------------------------------------------------------------------
	UpdateScreen();
	CWnd::OnTimer(nIDEvent);
}




BEGIN_MESSAGE_MAP(CFullWnd, CWnd)
	//{{AFX_MSG_MAP(CFullWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSCOMMAND()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
	ON_WM_MBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//----------------------------------------------------------------------------
CFullWnd::CFullWnd(){
//----------------------------------------------------------------------------
	m_brBk=NULL;
	m_uTimeTick = 150;
}

//----------------------------------------------------------------------------
CFullWnd::~CFullWnd(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
BOOL CFullWnd::CreateAsTop(void){
//----------------------------------------------------------------------------
	CRect rect(0, 0, ::GetSystemMetrics(SM_CXSCREEN),::GetSystemMetrics(SM_CYSCREEN));
	LPCSTR lpszClassName;
	lpszClassName = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,NULL,m_brBk);
	return CreateEx(WS_EX_TOPMOST, 
					lpszClassName, 
					_T(""), 
					WS_POPUP|WS_VISIBLE, 
					rect.left, 
					rect.top, 
					rect.right - rect.left, 
					rect.bottom - rect.top, 
					NULL, 
					NULL, 
					NULL);
}



//----------------------------------------------------------------------------
void CFullWnd::OnMouseMove(UINT nFlags, CPoint point){
//----------------------------------------------------------------------------
	static CPoint ptLast= point;

	if (ptLast != point)
		PostMessage(WM_CLOSE);
	CWnd::OnMouseMove(nFlags, point);
}

//----------------------------------------------------------------------------
void CFullWnd::OnLButtonDown(UINT nFlags, CPoint point){
//----------------------------------------------------------------------------
	PostMessage(WM_CLOSE);
	CWnd::OnLButtonDown(nFlags, point);
}

//----------------------------------------------------------------------------
void CFullWnd::OnMButtonDown(UINT nFlags, CPoint point){
//----------------------------------------------------------------------------
	PostMessage(WM_CLOSE);
	CWnd::OnMButtonDown(nFlags, point);
}

//----------------------------------------------------------------------------
void CFullWnd::OnRButtonDown(UINT nFlags, CPoint point){
//----------------------------------------------------------------------------
	PostMessage(WM_CLOSE);
	CWnd::OnRButtonDown(nFlags, point);
}

//----------------------------------------------------------------------------
void CFullWnd::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){
//----------------------------------------------------------------------------
	PostMessage(WM_CLOSE);
	CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

//----------------------------------------------------------------------------
void CFullWnd::OnSysCommand(UINT nID, LPARAM lParam){
//----------------------------------------------------------------------------
	if ((nID == SC_SCREENSAVE))
		return;
	CWnd::OnSysCommand(nID, lParam);
}

//----------------------------------------------------------------------------
void CFullWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){
//----------------------------------------------------------------------------
	PostMessage(WM_CLOSE);
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

//----------------------------------------------------------------------------
BOOL CFullWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) {
//----------------------------------------------------------------------------
	SetCursor(NULL);
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


//----------------------------------------------------------------------------
void CFullWnd::OnTimer(UINT nIDEvent){
//----------------------------------------------------------------------------
	UpdateScreen();
	CWnd::OnTimer(nIDEvent);
}

