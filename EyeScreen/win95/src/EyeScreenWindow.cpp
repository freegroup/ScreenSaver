/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */


#include "EyeScreenWindow.h"
#include "qapplication.h"
#include "qpainter.h"
#include "AnimatedObject.h"
#include <math.h>


static int timerId      = 0;
static int refresh_delay= 50;

//----------------------------------------------------------------------------
EyeScreenWindow::EyeScreenWindow( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name,WStyle_Maximize|WStyle_Customize |WStyle_StaysOnTop |WStyle_NoBorder  )
//	: QMainWindow( parent, name,f  )
//----------------------------------------------------------------------------
{
	m_width   =QApplication::desktop()->width();
	m_height  =QApplication::desktop()->height();

    m_buffer  = new QPixmap(m_width,m_height);

	setMouseTracking (true);
	setCursor(Qt::blankCursor);

	m_actionObject = new ActionObjectWrapper(m_width, m_height);
	startTimer(refresh_delay);
}


//----------------------------------------------------------------------------
void EyeScreenWindow::mousePressEvent ( QMouseEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void EyeScreenWindow::mouseReleaseEvent ( QMouseEvent * )
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void EyeScreenWindow::mouseDoubleClickEvent ( QMouseEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void EyeScreenWindow::mouseMoveEvent ( QMouseEvent *e ) 
//----------------------------------------------------------------------------
{
	static int x = e->x();
	static int y = e->y();
	if(x!= e->x() || y!=e->y())
		QApplication::exit(0);
}

//----------------------------------------------------------------------------
void EyeScreenWindow::wheelEvent ( QWheelEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//----------------------------------------------------------------------------
void EyeScreenWindow::keyPressEvent ( QKeyEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//----------------------------------------------------------------------------
void EyeScreenWindow::keyReleaseEvent ( QKeyEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//--------------------------------------------------------------------
void EyeScreenWindow::timerEvent(QTimerEvent*){
//--------------------------------------------------------------------

	static int x=0;

	m_buffer->fill(Qt::black);
   QPainter painter(m_buffer);

	m_actionObject->move();
   painter.drawPixmap(m_actionObject->getXPosition(),m_actionObject->getYPosition(),m_actionObject->framePixmap());
   painter.setPen(QPen(QColor(50,50,50), 2));
	painter.drawText(m_width-140,m_height-10,QString("<www.FreeGroup.de>"));
   bitBlt(this,0,0, m_buffer,0,0,m_width, m_height);
}
