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
ActionObject017::ActionObject017(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action017_*.png",8,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(0);
	setYSpeed(0);
	setPosition(startPos + QPoint(-80,-80));

	m_liveCounter= getFrameCount()*2;
}


//----------------------------------------------------------------------------
ActionObject* ActionObject017::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	setPosition(m_currentPosition + QPoint(80,80));
	switch(selection)
	{
	case 0:
		selection=0;
		return new ActionObject004(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
