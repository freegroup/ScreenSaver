#if !defined(AFX_CFLYINGUNDICHTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGUNDICHTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingUndichtCondomBitmap : public CAnimatedBitmap{
public:
	CFlyingUndichtCondomBitmap();
	virtual ~CFlyingUndichtCondomBitmap();
	virtual BOOL Move();
};

#endif