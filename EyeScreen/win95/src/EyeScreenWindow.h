/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "AnimatedObject.h"

#include <qmainwindow.h>
#include <qpixmap.h>
#include <qlist.h>
#include "ActionObjectWrapper.h"

class EyeScreenWindow : public QMainWindow
{
	Q_OBJECT
public:

	EyeScreenWindow( QWidget* parent = 0, const char* name = 0, WFlags f = WType_TopLevel );
	virtual void mousePressEvent ( QMouseEvent * ) ;
	virtual void mouseReleaseEvent ( QMouseEvent * ); 
	virtual void mouseDoubleClickEvent ( QMouseEvent * ) ;
	virtual void mouseMoveEvent ( QMouseEvent * ) ;
	virtual void wheelEvent ( QWheelEvent * ) ;
	virtual void keyPressEvent ( QKeyEvent * ) ;
	virtual void keyReleaseEvent ( QKeyEvent * ); 
	virtual void timerEvent(QTimerEvent*);

protected:

	ranAdd           m_random;
    QPixmap         *m_buffer;
	int              m_height;
	int              m_width;
    ActionObjectWrapper   *m_actionObject;

};

