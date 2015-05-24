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
ActionObject013::ActionObject013(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action013_*.png",1,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(0);
	setYSpeed(0);

	m_liveCounter= getFrameCount();
}



//----------------------------------------------------------------------------
ActionObject* ActionObject013::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	static int selection = 0;

	switch(selection)
	{
	case 0:
		selection++;
		return new ActionObject002(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 1:
		selection++;
		return new ActionObject009(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 2:
		selection =0;
		return new ActionObject003(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
