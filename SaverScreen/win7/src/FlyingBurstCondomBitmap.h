#if !defined(AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include <afxcoll.h>

#include "AnimatedBitmap.h"

class CFlyingBurstCondomBitmap : public CAnimatedBitmap{
public:
	CFlyingBurstCondomBitmap();
	virtual ~CFlyingBurstCondomBitmap();
	virtual BOOL Move();
};

#endif // !defined(AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
