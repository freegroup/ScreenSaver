/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingRaketeCondomBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingRaketeCondomBitmap::FlyingRaketeCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("rakete_condom*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------
}

//----------------------------------------------------------------------------
FlyingRaketeCondomBitmap::~FlyingRaketeCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingRaketeCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
