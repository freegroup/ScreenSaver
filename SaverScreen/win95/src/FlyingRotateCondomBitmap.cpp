/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingRotateCondomBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingRotateCondomBitmap::FlyingRotateCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("rotate_condom*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------
}

//----------------------------------------------------------------------------
FlyingRotateCondomBitmap::~FlyingRotateCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingRotateCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
