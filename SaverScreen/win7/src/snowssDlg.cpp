//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : snowssDlg.cpp 
// Created : 05/28/1999 03:19:14 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "snowss.h"
#include "snowssDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CSnowssDlg dialog

CSnowssDlg::CSnowssDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnowssDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSnowssDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnowssDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnowssDlg)
	DDX_Control(pDX, IDC_COUNT_SPIN,  m_countSpin);
	DDX_Control(pDX, IDC_COUNT_EDIT,  m_countEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSnowssDlg, CDialog)
	//{{AFX_MSG_MAP(CSnowssDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DEF, OnDef)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnowssDlg message handlers

BOOL CSnowssDlg::OnInitDialog()
{
	CDialog::OnInitDialog();



	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_countSpin.SetBuddy(&m_countEdit);

	GetSetting();
	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CSnowssDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else{
		CDialog::OnPaint();
	}
}


void CSnowssDlg::OnOK(void)
{
	PutSetting();
}


void CSnowssDlg::GetSetting(void){
	CWinApp* pA=AfxGetApp();
	m_count=pA->GetProfileInt("Options","Count",10);

	m_countSpin.SetRange(10.0f, 100.0f);
	m_countSpin.SetDelta(5.0f);
	m_countSpin.SetPos((float)m_count);
}


void CSnowssDlg::PutSetting(void){
	CWinApp* pA=AfxGetApp();
	m_count=(int)m_countSpin.GetPos();
	pA->WriteProfileInt("Options","Count",m_count);

	CDialog::OnOK();
}


void CSnowssDlg::OnDef() {
	m_countSpin.SetPos((float)20);
}
