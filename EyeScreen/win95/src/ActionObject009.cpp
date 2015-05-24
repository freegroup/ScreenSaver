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
ActionObject009::ActionObject009(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action009_*.png",1,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	m_endPosX = startPos.x()- ((m_random.gen()%100)+30);
	m_endPosY = startPos.y()+ ((screenHeight) / ((m_random.gen()%40)+40)*getSignum());
	setXSpeed((m_endPosX-startPos.x())/getImageCount()); 
	setYSpeed((m_endPosY-startPos.y())/getImageCount()); 
}



//----------------------------------------------------------------------------
ActionObject* ActionObject009::getSuccessor(bool objectVisible)
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
		return new ActionObject010(m_screenWidth, m_screenHeight, m_currentPosition);
		break;
	default:
		selection =0;
		break;
	}

	return NULL;
}
