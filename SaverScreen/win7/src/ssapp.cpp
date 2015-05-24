//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : ssapp.cpp 
// Created : 05/28/1999 03:19:19 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ssbase.h"

BEGIN_MESSAGE_MAP(CSSApp, CWinApp)
	//{{AFX_MSG_MAP(CSSApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//----------------------------------------------------------------------------
CSSApp::CSSApp(){
//----------------------------------------------------------------------------
	srand(time(NULL));
}

//----------------------------------------------------------------------------
CSSApp::~CSSApp(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
BOOL CSSApp::MatchOption(LPTSTR lpsz, LPTSTR lpszOption){
//----------------------------------------------------------------------------
	if (lpsz[0] == _T('-') || lpsz[0] == _T('/'))
		lpsz++;
	if (lstrcmpi(lpsz, lpszOption) == 0)
		return TRUE;
	return FALSE;
}


//----------------------------------------------------------------------------
BOOL CSSApp::InitInstance(){
//----------------------------------------------------------------------------
	SetRegistryKey(_T("FREE SaverScreen"));

	if (__argc == 1 || __argv[1][1]=='c'||__argv[1][0]=='c') {
		DoConfig();
	}
	else {
		if (MatchOption(__argv[1], _T("p"))){
			return DoSmall();
		}
		else {
			if (MatchOption(__argv[1], _T("s"))){
				return DoFull();
			}
		}
	}

	return FALSE;
}


//----------------------------------------------------------------------------
BOOL CSSApp::DoConfig(void){
//----------------------------------------------------------------------------
	return FALSE;
}


//----------------------------------------------------------------------------
BOOL CSSApp::DoSmall(void){
//----------------------------------------------------------------------------
	CWnd* pParent = CWnd::FromHandle((HWND)atol(__argv[2]));
	ASSERT(pParent != NULL);
	CSmallWnd* pWnd = GetSmallWindow();
	if(pWnd->CreateAsShow(pParent))	{
		m_pMainWnd = pWnd;
		return TRUE;
	}

	return FALSE;
}



//----------------------------------------------------------------------------
BOOL CSSApp::DoFull(void){
//----------------------------------------------------------------------------
	CFullWnd* pWnd = GetFullWindow();
	if(pWnd->CreateAsTop())	{
		m_pMainWnd = pWnd;
		return TRUE;
	}

	return FALSE;
}
