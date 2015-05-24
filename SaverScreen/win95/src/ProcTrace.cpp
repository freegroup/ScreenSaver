/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "ProcTrace.h"
#include <qfile.h>


//----------------------------------------------------------------------------
ProcTrace::ProcTrace(char *message)
//----------------------------------------------------------------------------
{
	m_message = message;
	QFile file;
	file.open(IO_WriteOnly|IO_Append);
	file.writeBlock(m_message.data(), m_message.length());
	debug(m_message.data());
}

//----------------------------------------------------------------------------
ProcTrace::~ProcTrace()
//----------------------------------------------------------------------------
{
	QFile file;
	file.open(IO_WriteOnly|IO_Append);
	file.writeBlock(m_message.data(), m_message.length());
	debug(m_message.data());
}
