#ifndef __CSNOWSSDLG__H_
#define __CSNOWSSDLG__H_

#include "NumEdit.h"
#include "NumSpinCtrl.h"

class CSnowssDlg : public CDialog
{
// Construction
public:
	CSnowssDlg(CWnd* pParent = NULL);	// standard constructor
	virtual void OnOK(void);
	void GetSetting(void);
	void PutSetting(void);
// Dialog Data
	//{{AFX_DATA(CSnowssDlg)
	enum { IDD = IDD_SNOWSS_DIALOG };
	CNumSpinCtrl	m_countSpin;
	CNumEdit    	m_countEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnowssDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	long  m_count;

	// Generated message map functions
	//{{AFX_MSG(CSnowssDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnDef();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif
