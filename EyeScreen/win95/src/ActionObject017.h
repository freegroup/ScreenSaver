/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT017_H__7EB7B55A_D26C_11D4_A66B_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT017_H__7EB7B55A_D26C_11D4_A66B_00104B59BDBD__INCLUDED_

#include "ActionObject.h"

class ActionObject017 : public ActionObject
{
public:
	ActionObject017(int screenWidth, int screenHeight, QPoint startPos);

	virtual ActionObject* getSuccessor(bool objectVisible);

protected:
};



#endif // !defined(AFX_ACTIONOBJECT017_H__7EB7B55A_D26C_11D4_A66B_00104B59BDBD__INCLUDED_)
