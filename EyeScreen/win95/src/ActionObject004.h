/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT004_H__E4080854_D10B_11D4_A668_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT004_H__E4080854_D10B_11D4_A668_00104B59BDBD__INCLUDED_
#include "ActionObject.h"

class ActionObject004 : public ActionObject
{
public:
	ActionObject004(int screenWidth, int screenHeight, QPoint startPos);

	virtual ActionObject* getSuccessor(bool objectVisible);
	virtual int           getYPosition();

protected:
};


#endif // !defined(AFX_ACTIONOBJECT004_H__E4080854_D10B_11D4_A668_00104B59BDBD__INCLUDED_)
