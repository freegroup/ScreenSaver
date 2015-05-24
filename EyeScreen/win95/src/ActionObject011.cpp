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
ActionObject011::ActionObject011(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action010_*.png",6,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	setXSpeed(-50); 
	setYSpeed(+2); 
	m_liveCounter= getFrameCount();
}


//----------------------------------------------------------------------------
ActionObject* ActionObject011::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	switch(selection)
	{
	case 0:
		selection++;
		return new ActionObject003(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 1:
		selection =0;
		return new ActionObject013(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
