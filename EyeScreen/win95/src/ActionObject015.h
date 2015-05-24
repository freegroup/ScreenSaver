/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ACTIONOBJECT015_H__41D3D47E_D1C4_11D4_A669_00104B59BDBD__INCLUDED_)
#define AFX_ACTIONOBJECT015_H__41D3D47E_D1C4_11D4_A669_00104B59BDBD__INCLUDED_

#include "ActionObject.h"

class ActionObject015 : public ActionObject
{
public:
	ActionObject015(int screenWidth, int screenHeight, QPoint startPos);

	virtual ActionObject* getSuccessor(bool objectVisible);

protected:
};


#endif // !defined(AFX_ACTIONOBJECT015_H__41D3D47E_D1C4_11D4_A669_00104B59BDBD__INCLUDED_)
