/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECTWRAPPER_H__D9C4525B_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECTWRAPPER_H__D9C4525B_D0EC_11D4_A668_00104B59BDBD__INCLUDED_

#include "qpixmap.h"
#include "ActionObject.h"

class ActionObjectWrapper  
{
public:
	ActionObjectWrapper(int screenWidth, int screenHeight);
	virtual ~ActionObjectWrapper();

	virtual int  getXPosition();
	virtual int  getYPosition();
	virtual bool move();
    QPixmap&     framePixmap();

protected:
	ActionObject *m_actionObject;
};

#endif // !defined(AFX_ACTIONOBJECTWRAPPER_H__D9C4525B_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
