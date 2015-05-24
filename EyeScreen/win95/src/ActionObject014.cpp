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
ActionObject014::ActionObject014(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action014_*.png",1,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setPosition(startPos + QPoint(0,-90));
	setXSpeed(0);
	setYSpeed(0);

	m_liveCounter= getFrameCount()*5;
}


//----------------------------------------------------------------------------
ActionObject* ActionObject014::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;
    m_currentPosition= m_currentPosition + QPoint(0,90);

	switch(selection)
	{
	case 0:
		selection++;
		return new ActionObject007(m_screenWidth, m_screenHeight,m_currentPosition);
		break;
	case 1:
		selection++;
		return new ActionObject005(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 2:
		selection++;
		return new ActionObject015(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 3:
		selection =0;
		return new ActionObject004(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
