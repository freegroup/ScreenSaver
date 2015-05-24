/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT002_H__D9C4525D_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT002_H__D9C4525D_D0EC_11D4_A668_00104B59BDBD__INCLUDED_

#include "ActionObject.h"

class ActionObject002 : public ActionObject  
{
public:
	ActionObject002(int screenWidth, int screenHeight, QPoint startPos);

	virtual ActionObject* getSuccessor(bool objectVisible);
};

#endif // !defined(AFX_ACTIONOBJECT002_H__D9C4525D_D0EC_11D4_A668_00104B59BDBD__INCLUDED_)
