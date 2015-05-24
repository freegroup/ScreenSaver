#if !defined(AFX_CFLYINGREVERSECONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGREVERSECONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingReverseCondomBitmap : public CAnimatedBitmap{
public:
	CFlyingReverseCondomBitmap();
	virtual ~CFlyingReverseCondomBitmap();
	virtual BOOL Move();
};

#endif