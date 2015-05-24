#if !defined(AFX_CFLYINGROTATECONDOM2BITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGROTATECONDOM2BITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingRotateCondomBitmap : public CAnimatedBitmap{
public:
	CFlyingRotateCondomBitmap();
	virtual ~CFlyingRotateCondomBitmap();
	virtual BOOL Move();
};

#endif