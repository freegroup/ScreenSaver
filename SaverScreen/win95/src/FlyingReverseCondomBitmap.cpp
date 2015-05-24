/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingReverseCondomBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingReverseCondomBitmap::FlyingReverseCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("reverse_condom*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------
}

//----------------------------------------------------------------------------
FlyingReverseCondomBitmap::~FlyingReverseCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
bool FlyingReverseCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
