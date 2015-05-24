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
ActionObject004::ActionObject004(int screenWidth, int screenHeight, QPoint startPos)
:ActionObject("action004_*.png",2,screenWidth,screenHeight, startPos)
{
//----------------------------------------------------------------------------

	// determine the end position of the object
	//
	m_endPosX = screenWidth/2  + ((m_random.gen()%200)+1);
	m_endPosY = screenHeight/3;

	setXSpeed((m_endPosX-startPos.x())/getImageCount()); 
	setYSpeed((m_endPosY-startPos.y())/getImageCount()); 
}


//----------------------------------------------------------------------------
int ActionObject004::getYPosition()
//----------------------------------------------------------------------------
{
	return AnimatedObject::getYPosition();
}

//----------------------------------------------------------------------------
ActionObject* ActionObject004::getSuccessor(bool objectVisible)
//----------------------------------------------------------------------------
{
	return new ActionObject002(m_screenWidth, m_screenHeight,m_currentPosition);
}
