/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_



#include "AnimatedObject.h"

class FlyingBurstCondomBitmap : public AnimatedObject{
public:
	FlyingBurstCondomBitmap(int screenWidth, int screenHeight);
	virtual ~FlyingBurstCondomBitmap();
	virtual bool move();
};

#endif // !defined(AFX_CFLYINGBURSTCONDOMBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
