#ifndef __CFULLCONDOMWND__H_
#define __CFULLCONDOMWND__H_

#include "AnimatedBitmap.h"
#include "ranAdd.H"

class CFullCondomWnd : public CFullWnd
{
public:
	CFullCondomWnd();

	virtual void UpdateScreen(void);

protected:
	CObArray           m_aniImageCollection;
	ranAdd m_random;

	virtual void InsertNewObject();

	//{{AFX_MSG(CFullCondomWnd)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif