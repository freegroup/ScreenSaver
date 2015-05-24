/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */


#include "AnimatedObject.h"
#include "ProcTrace.h"

ranAdd		AnimatedObject::m_random;

//----------------------------------------------------------------------------
AnimatedObject::AnimatedObject(QString filepattern, int screenWidth, int screenHeight){
//----------------------------------------------------------------------------

	m_animation       = new Animation(filepattern,1,true);
	m_markedForDelete = false;
	m_currentPosition = QPoint(0,0);
	m_screenHeight    = screenWidth;
	m_screenWidth     = screenHeight;

	for( unsigned int i=0; i<m_random.gen()%20;)
	{
		m_animation->step();
	}
}

//----------------------------------------------------------------------------
AnimatedObject::~AnimatedObject(){
//----------------------------------------------------------------------------

	delete m_animation;
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
		if(m_currentPosition.x()<(-200))
		{
			m_currentPosition.setX(m_screenWidth+200);
			result = false;
		}
	}
	else
	{
		if(m_currentPosition.x()>(m_screenWidth+400))
		{
			m_currentPosition.setX(-400);
			result = false;
		}
	}

	if(offset.y()>0)
	{
		if(m_currentPosition.y()>(m_screenHeight+200))
		{
			m_currentPosition.setY(-200);
			result = false;
		}
	}
	else
	{
		if(m_currentPosition.y()<(-200))
		{
			m_currentPosition.setY(m_screenHeight+200);
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
