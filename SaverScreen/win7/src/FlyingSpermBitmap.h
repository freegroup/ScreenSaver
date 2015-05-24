#if !defined(AFX_CFLYINGSPERMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGSPERMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingSpermBitmap : public CAnimatedBitmap{
public:
	CFlyingSpermBitmap();
	virtual ~CFlyingSpermBitmap();
	virtual BOOL Move();
};

#endif