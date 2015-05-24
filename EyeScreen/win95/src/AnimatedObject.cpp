/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "AnimatedObject.h"

ranAdd		AnimatedObject::m_random;

//----------------------------------------------------------------------------
AnimatedObject::AnimatedObject(QString filepattern, int imagesPerFrame,int screenWidth, int screenHeight, QPoint startPos){
//----------------------------------------------------------------------------

	m_animation       = new Animation(filepattern,imagesPerFrame,true);
	m_currentPosition = startPos;
	m_screenHeight    = screenWidth;
	m_screenWidth     = screenHeight;
}

//----------------------------------------------------------------------------
AnimatedObject::~AnimatedObject(){
//----------------------------------------------------------------------------

	delete m_animation;
}

//----------------------------------------------------------------------------
int AnimatedObject::getImageCount()
//----------------------------------------------------------------------------
{
	return m_animation->getImageCount();
}

//----------------------------------------------------------------------------
int AnimatedObject::getFrameCount()
//----------------------------------------------------------------------------
{
	return m_animation->getFrameCount();
}


//----------------------------------------------------------------------------
bool AnimatedObject::move(){
//----------------------------------------------------------------------------
	return moveRel(m_speed);
}


//----------------------------------------------------------------------------
bool AnimatedObject::moveRel(QPoint offset){
//----------------------------------------------------------------------------

	bool result = true;

	m_animation->step();

	m_currentPosition += QPoint(offset.x(),offset.y());
	if(offset.x() < 0)
	{
		if(m_currentPosition.x()<(-100))
		{
			result = false;
		}
	}
	else
	{
		if(m_currentPosition.x()>(m_screenWidth+100))
		{
			result = false;
		}
	}

	if(offset.y()>0)
	{
		if(m_currentPosition.y()>(m_screenHeight+100))
		{
			result = false;
		}
	}
	else
	{
		if(m_currentPosition.y()<(-100))
		{
			result = false;
		}
	}
	return result;
}


//----------------------------------------------------------------------------
QPixmap& AnimatedObject::framePixmap(){
//----------------------------------------------------------------------------
   
   return m_animation->framePixmap();
}
