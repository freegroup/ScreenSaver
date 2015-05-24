/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingCondom2Bitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingPinkCondomBitmap::FlyingPinkCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("pink_condom*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------
}

//----------------------------------------------------------------------------
FlyingPinkCondomBitmap::~FlyingPinkCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingPinkCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
