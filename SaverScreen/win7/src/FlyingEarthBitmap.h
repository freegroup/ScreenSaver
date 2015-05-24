#if !defined(AFX_CFLYINGEARTHBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGEARTHBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingEarthBitmap : public CAnimatedBitmap{
public:
	CFlyingEarthBitmap();
	virtual ~CFlyingEarthBitmap();
	virtual BOOL Move();
};

#endif // !defined(AFX_CFLYINGCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
