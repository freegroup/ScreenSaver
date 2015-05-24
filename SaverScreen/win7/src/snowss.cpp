//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : snowss.cpp 
// Created : 05/28/1999 03:19:08 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "snowss.h"
#include "snowssDlg.h"
#include "snowwnd.h"
#include "showwnd.h"


CCondomScreenSaverApp theApp;


//----------------------------------------------------------------------------
CCondomScreenSaverApp::CCondomScreenSaverApp(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
BOOL CCondomScreenSaverApp::InitInstance(){
//----------------------------------------------------------------------------

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	return CSSApp::InitInstance();
}


//----------------------------------------------------------------------------
BOOL CCondomScreenSaverApp::DoConfig(void){
//----------------------------------------------------------------------------
	CSnowssDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK){
	}
	else if (nResponse == IDCANCEL)	{
	}

	return FALSE;
}