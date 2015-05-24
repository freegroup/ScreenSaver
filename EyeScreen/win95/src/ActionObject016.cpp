/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "ActionObjects.h"

//----------------------------------------------------------------------------
ActionObject016::ActionObject016(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action016_*.png",4,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(0);
	setYSpeed(0);
	setPosition(startPos + QPoint(-80,-80));

	m_liveCounter= getFrameCount();
}


//----------------------------------------------------------------------------
ActionObject* ActionObject016::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	setPosition(m_currentPosition + QPoint(80,80));
	switch(selection)
	{
	case 0:
		selection=0;
		return new ActionObject017(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
