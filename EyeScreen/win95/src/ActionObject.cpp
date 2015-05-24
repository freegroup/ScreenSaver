/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "math.h"
#include "ActionObject.h"

//----------------------------------------------------------------------------
ActionObject::ActionObject(QString filepattern, int imagesPerFrame,int screenWidth, int screenHeight, QPoint startPos)
:AnimatedObject(filepattern,imagesPerFrame, screenWidth,screenHeight, startPos)
//----------------------------------------------------------------------------
{
	m_liveCounter=-1;  // live for ever
}

//----------------------------------------------------------------------------
ActionObject::~ActionObject()
//----------------------------------------------------------------------------
{

}

//----------------------------------------------------------------------------
int ActionObject::getSignum()
//----------------------------------------------------------------------------
{
	return (((m_random.gen()%4)-2)>0? -1:1);
}


//----------------------------------------------------------------------------
bool ActionObject::move()
//----------------------------------------------------------------------------
{
	if(m_liveCounter>0)
	{
		m_liveCounter--;
		if (m_liveCounter==0)
			return false;
	}
	else
	{
		if((m_speed.x()>0) && (m_currentPosition.x()>m_endPosX))
			return false;

		if((m_speed.x()<0) && (m_currentPosition.x()<m_endPosX))
			return false;

		if((m_speed.y()>0) && (m_currentPosition.y()>m_endPosY))
			return false;

		if((m_speed.y()<0) && (m_currentPosition.y()<m_endPosY))
			return false;
	}

	return AnimatedObject::move();
}

//----------------------------------------------------------------------------
int ActionObject::getYPosition()
//----------------------------------------------------------------------------
{
	static float xStrech = 3;
	static float yStrech = 3;

	float newYPos = abs(sin(m_currentPosition.x()/(xStrech*m_speed.x())) * (yStrech*m_speed.x()));


	return m_currentPosition.y()+(int)newYPos;
}
