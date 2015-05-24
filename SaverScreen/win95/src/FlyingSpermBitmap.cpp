/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingSpermBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingSpermBitmap::FlyingSpermBitmap(int screenWidth, int screenHeight)
:AnimatedObject("sperm*.png",screenWidth,screenHeight)
//----------------------------------------------------------------------------
{
}

//----------------------------------------------------------------------------
FlyingSpermBitmap::~FlyingSpermBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingSpermBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
