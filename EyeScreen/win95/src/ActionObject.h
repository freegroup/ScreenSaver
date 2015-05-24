/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT_H__D9C4525C_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT_H__D9C4525C_D0EC_11D4_A668_00104B59BDBD__INCLUDED_


#include "AnimatedObject.h"

class ActionObject : public AnimatedObject  
{
public:
	ActionObject(QString filepattern,int imagesPerFrame,int screenWidth, int screenHeight, QPoint startPos);
	virtual ~ActionObject();

	virtual ActionObject* getSuccessor(bool objectVisible)=0;
	virtual bool          move();
	virtual int           getYPosition();
	virtual int           getSignum();

protected:
	int     m_endPosX;
	int     m_endPosY;
	int     m_liveCounter;
};

#endif // !defined(AFX_ACTIONOBJECT_H__D9C4525C_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
