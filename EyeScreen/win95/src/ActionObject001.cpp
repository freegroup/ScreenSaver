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
ActionObject001::ActionObject001(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action001_*.png",1,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// init the object 
	//
	setXSpeed(15);

	// determine the end position of the object
	//
	m_endPosX = startPos.x()+ (screenWidth)  / ((m_random.gen()%4)+2);
	m_endPosY = startPos.y()+ ((screenHeight) / ((m_random.gen()%20)+10)*getSignum());

	int steps = (startPos.x() - m_endPosX)/15;
	setYSpeed((startPos.y() - m_endPosY)/steps);
}


//----------------------------------------------------------------------------
ActionObject* ActionObject001::getSuccessor(bool objectVisible)
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
		return new ActionObject003(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	case 2:
		selection=0;
		return new ActionObject008(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
