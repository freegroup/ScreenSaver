#ifndef __SSBASE_H
#define __SSBASE_H

class CSmallWnd;
class CFullWnd;
#include "ranAdd.H"


class CSSApp : public CWinApp
{
public:
	BOOL MatchOption(LPTSTR lpsz, LPTSTR lpszOption);

	virtual CSmallWnd* GetSmallWindow()=0;
	virtual CFullWnd*  GetFullWindow() =0;
	
	virtual BOOL InitInstance();

	virtual BOOL DoConfig(void);
	virtual BOOL DoSmall(void);
	virtual BOOL DoFull(void);

protected:
	CSSApp();           // protected constructor used by dynamic creation
	virtual ~CSSApp();

	DECLARE_MESSAGE_MAP()
};


class CSmallWnd : public CWnd{
public:
	CSmallWnd();
	virtual ~CSmallWnd();

	virtual BOOL CreateAsShow(CWnd* pParent);
	virtual void UpdateScreen()=0;

protected:
	UINT m_uTimeTick;
	HBRUSH m_brBk;
	ranAdd m_random;

	//{{AFX_MSG(CSmallWnd)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


class CFullWnd : public CWnd{
public:
	CFullWnd();
	virtual ~CFullWnd();

	virtual BOOL CreateAsTop(void);
	virtual void UpdateScreen()=0;


protected:
	UINT m_uTimeTick;
	HBRUSH m_brBk;

	//{{AFX_MSG(CFullWnd)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif
