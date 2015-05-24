// AnimatedBitmap.h: interface for the CAnimatedBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANIMATEDBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_ANIMATEDBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "TransparentBitmap.h"
#include "ranAdd.H"

class CAnimatedBitmap : public CObject{
public:
	CAnimatedBitmap();
	virtual ~CAnimatedBitmap();

	virtual void Draw(CDC * pDC, COLORREF crColour= RGB(0,0,0));
	virtual void Insert(UINT DrawResId);

	virtual int Height();
	virtual int Width();

	virtual void SetXSpeed(int x){m_speed.x = x;};
	virtual void SetYSpeed(int y){m_speed.y = y;};
	virtual void SetPosition(CPoint p){m_currentPosition = p;};
	virtual BOOL IsMarkedForDelete(){return m_markedForDelete;};

	virtual BOOL MoveRel(CPoint offset);
	virtual BOOL Move();
	virtual void SetDrawRect(CRect rect){m_drawRect = rect;	};


protected:
	BOOL        m_markedForDelete;
	CObArray    m_drawBitmapCollection;
	CRect		m_drawRect;
	CPoint      m_currentPosition;
    CPoint      m_speed;
	int         m_currentImage;

    static ranAdd		m_random;
};

#endif // !defined(AFX_CISBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
