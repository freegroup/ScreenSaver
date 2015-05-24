/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_CFLYINGBIGCONDOM2BITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CFLYINGBIGCONDOM2BITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_



#include "AnimatedObject.h"

class FlyingBigCondomBitmap : public AnimatedObject{
public:
	FlyingBigCondomBitmap(int screenWidth, int screenHeight);
	virtual ~FlyingBigCondomBitmap();
	virtual bool move();
};

#endif