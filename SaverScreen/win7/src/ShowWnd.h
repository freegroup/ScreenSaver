#ifndef __CSHOWWND__H_
#define __CSHOWWND__H_

#include "AnimatedBitmap.h"
#include "ranAdd.H"

class CSmallCondomWnd : public CSmallWnd{
public:
	CSmallCondomWnd();
	virtual ~CSmallCondomWnd();

	virtual void UpdateScreen();

protected:
	CObArray           m_aniImageCollection;

	//{{AFX_MSG(CSmallCondomWnd)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
