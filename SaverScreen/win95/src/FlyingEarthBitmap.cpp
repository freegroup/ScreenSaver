/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingEarthBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingEarthBitmap::FlyingEarthBitmap(int screenWidth, int screenHeight)
:AnimatedObject("rthx*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------
}

//----------------------------------------------------------------------------
FlyingEarthBitmap::~FlyingEarthBitmap(){
//----------------------------------------------------------------------------

}



//----------------------------------------------------------------------------
bool FlyingEarthBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
