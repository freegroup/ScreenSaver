/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingUndichtCondomBitmap.h"
#include "ProcTrace.h"

//----------------------------------------------------------------------------
FlyingUndichtCondomBitmap::FlyingUndichtCondomBitmap(int screenWidth, int screenHeight)
//----------------------------------------------------------------------------
:AnimatedObject("undicht_condom*.png",screenWidth,screenHeight)
{
}

//----------------------------------------------------------------------------
FlyingUndichtCondomBitmap::~FlyingUndichtCondomBitmap()
//----------------------------------------------------------------------------
{
}

//----------------------------------------------------------------------------
bool FlyingUndichtCondomBitmap::move()
//----------------------------------------------------------------------------
{
   m_markedForDelete = !moveRel(m_speed);
	return !m_markedForDelete;
}
