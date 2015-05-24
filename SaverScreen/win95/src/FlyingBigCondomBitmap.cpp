/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingBigCondomBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingBigCondomBitmap::FlyingBigCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("big_condom*.png",screenWidth,screenHeight)
//----------------------------------------------------------------------------
{
}

//----------------------------------------------------------------------------
FlyingBigCondomBitmap::~FlyingBigCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingBigCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
