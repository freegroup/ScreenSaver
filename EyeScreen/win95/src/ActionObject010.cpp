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
ActionObject010::ActionObject010(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action010_*.png",((m_random.gen()%40)+1),screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(0);
	setYSpeed(0);

	m_liveCounter= getFrameCount();
}



//----------------------------------------------------------------------------
ActionObject* ActionObject010::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	switch(selection)
	{
	case 0:
		selection++;
		return new ActionObject006(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 1:
		selection =0;
		return new ActionObject011(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
