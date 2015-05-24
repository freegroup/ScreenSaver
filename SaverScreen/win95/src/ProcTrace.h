/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_PROCTRACE1_H__2E46C829_D0E1_11D4_A668_00104B59BDBD__INCLUDED_)
#define AFX_PROCTRACE1_H__2E46C829_D0E1_11D4_A668_00104B59BDBD__INCLUDED_

#include "qstring.h"

class ProcTrace  
{
public:
	ProcTrace(char *);
	virtual ~ProcTrace();

protected:
	QString m_message;

};

#define PROC_TRACE(x)   static char __FUNCTION__[] = x;                  \
                        ProcTrace stackTraceObject(__FUNCTION__);         

#endif // !defined(AFX_PROCTRACE1_H__2E46C829_D0E1_11D4_A668_00104B59BDBD__INCLUDED_)
