/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT0016_H__7EB7B559_D26C_11D4_A66B_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT0016_H__7EB7B559_D26C_11D4_A66B_00104B59BDBD__INCLUDED_

#include "ActionObject.h"

class ActionObject016 : public ActionObject
{
public:
	ActionObject016(int screenWidth, int screenHeight, QPoint startPos);

	virtual ActionObject* getSuccessor(bool objectVisible);

protected:
};



#endif // !defined(AFX_ACTIONOBJECT0016_H__7EB7B559_D26C_11D4_A66B_00104B59BDBD__INCLUDED_)
