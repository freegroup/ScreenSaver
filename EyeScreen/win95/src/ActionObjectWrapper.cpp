/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "ActionObjectWrapper.h"
#include "ActionObjects.h"


//----------------------------------------------------------------------------
ActionObjectWrapper::ActionObjectWrapper(int screenWidth, int screenHeight)
//----------------------------------------------------------------------------
{
	m_actionObject = new ActionObject006(screenWidth, screenHeight, QPoint(300,300));
}

//----------------------------------------------------------------------------
ActionObjectWrapper::~ActionObjectWrapper()
//----------------------------------------------------------------------------
{
	delete m_actionObject;
}

//----------------------------------------------------------------------------
int  ActionObjectWrapper::getXPosition()
//----------------------------------------------------------------------------
{
	return m_actionObject->getXPosition();
}

//----------------------------------------------------------------------------
int  ActionObjectWrapper::getYPosition()
//----------------------------------------------------------------------------
{
	return m_actionObject->getYPosition();
}


//----------------------------------------------------------------------------
QPixmap& ActionObjectWrapper::framePixmap()
//----------------------------------------------------------------------------
{
	return m_actionObject->framePixmap();
}

//----------------------------------------------------------------------------
bool ActionObjectWrapper::move()
//----------------------------------------------------------------------------
{
	bool result = m_actionObject->move();

	if(result == false)
	{
		ActionObject* newAction = m_actionObject->getSuccessor(true);
		delete m_actionObject;
		m_actionObject = newAction;
	}
	return result;
}
