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
ActionObject012::ActionObject012(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action012_*.png",1,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(0);
	setYSpeed(0);

	m_liveCounter= getFrameCount()*3;
}



//----------------------------------------------------------------------------
ActionObject* ActionObject012::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	switch(selection)
	{
	case 0:
		selection++;
		return new ActionObject005(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 1:
		selection++;
		return new ActionObject014(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 2:
		selection++;
		return new ActionObject015(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 3:
		selection =0;
		return new ActionObject010(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
