/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "SaverScreenWindow.h"
#include "qapplication.h"
#include "qpainter.h"
#include "AnimatedObject.h"
#include "FlyingCondomBitmap.h"
#include "FlyingCondom2Bitmap.h"
#include "FlyingReverseCondomBitmap.h"
#include "FlyingUndichtCondomBitmap.h"
#include "FlyingRotateCondomBitmap.h"
#include "FlyingBigCondomBitmap.h"
#include "FlyingRaketeCondomBitmap.h"
#include "FlyingSpermBitmap.h"
#include "FlyingEarthBitmap.h"
#include "FlyingBurstCondomBitmap.h"
#include <math.h>
#include "ProcTrace.h"


static int timerId      = 0;
static int refresh_delay= 100;

//----------------------------------------------------------------------------
SaverScreenWindow::SaverScreenWindow( QWidget* parent, const char* name, WFlags f )
	: QMainWindow( parent, name,WStyle_Customize |WStyle_StaysOnTop |WStyle_NoBorder  )
//----------------------------------------------------------------------------
{
	m_objects.setAutoDelete(true);

	m_width   =QApplication::desktop()->width();
	m_height  =QApplication::desktop()->height();

    m_buffer  = new QPixmap(m_width,m_height);

	// Add your code
	setMouseTracking (true);
	setCursor(Qt::blankCursor);

	AnimatedObject *newImage=NULL;
	for(int  i=0;i<20;i++)
	{
		newImage = new FlyingCondomBitmap(m_width, m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%5))-2);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(m_random.gen()% m_width,m_random.gen()% m_height));
		m_objects.append(newImage);
	}
	startTimer(refresh_delay);

}


//----------------------------------------------------------------------------
void SaverScreenWindow::mousePressEvent ( QMouseEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void SaverScreenWindow::mouseReleaseEvent ( QMouseEvent * )
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void SaverScreenWindow::mouseDoubleClickEvent ( QMouseEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}


//----------------------------------------------------------------------------
void SaverScreenWindow::mouseMoveEvent ( QMouseEvent *e ) 
//----------------------------------------------------------------------------
{
	static int x = e->x();
	static int y = e->y();

	if(x!= e->x() || y!=e->y())
		QApplication::exit(0);
}

//----------------------------------------------------------------------------
void SaverScreenWindow::wheelEvent ( QWheelEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//----------------------------------------------------------------------------
void SaverScreenWindow::keyPressEvent ( QKeyEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//----------------------------------------------------------------------------
void SaverScreenWindow::keyReleaseEvent ( QKeyEvent * ) 
//----------------------------------------------------------------------------
{
	QApplication::exit(0);
}

//--------------------------------------------------------------------
void SaverScreenWindow::timerEvent(QTimerEvent*){
//--------------------------------------------------------------------

	static int x=0;
	static long randomCounter = 0;

	m_buffer->fill(Qt::black);
    QPainter painter(m_buffer);

	for(unsigned int i=0; i<m_objects.count();i++)
	{
		AnimatedObject *obj = m_objects.at(i);
		obj->move();
	    painter.drawPixmap(obj->getXPosition(),obj->getYPosition(),obj->framePixmap());
		if(obj->isMarkedForDelete())
		{
			m_objects.remove(i);
		}
	}
	painter.setPen(QPen(QColor(50,50,50), 2));
 	painter.drawText(m_width-150,m_height-10,QString("<www.FreeGroup.de>"));
   bitBlt(this,0,0, m_buffer,0,0,m_width, m_height);


	if(randomCounter == 0 ){
		insertNewObject();
		randomCounter = abs(m_random.gen()%200)+50;
	}

	if(randomCounter >0)
		randomCounter--;
}



//----------------------------------------------------------------------------
void SaverScreenWindow::insertNewObject(){
//----------------------------------------------------------------------------
	static long counter = 7;
	long xPos=0;
	long yPos=0;
	AnimatedObject *newImage=NULL;

	xPos = m_width ;
	yPos = m_random.gen()% (1>m_height-100?1:m_height-100);

	switch(counter++){
	case 0:
		newImage = new FlyingRaketeCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-8);
		newImage->setYSpeed(0);
		newImage->setPosition(QPoint(xPos,yPos));
		break;
	case 1:
		newImage = new FlyingBigCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%5))-2);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(xPos,yPos));
		break;
	case 2:
		newImage = new FlyingRotateCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%5))-3);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(xPos,yPos));
		break;
	case 3:
		newImage = new FlyingUndichtCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%5))-3);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(xPos,yPos));
		break;
	case 4:
		newImage = new FlyingReverseCondomBitmap(m_width,m_height);
		newImage->setXSpeed((abs((long)m_random.gen()%7))+20);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(-10,yPos));
		break;
	case 5:
		newImage = new FlyingSpermBitmap(m_width,m_height);
		newImage->setXSpeed((abs((long)m_random.gen()%7))+20);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(-10,yPos));
		break;
	case 6:
		newImage = new FlyingEarthBitmap(m_width,m_height);
		newImage->setXSpeed(1);
		newImage->setYSpeed(0);
		newImage->setPosition(QPoint(-10,yPos));
		break;
		/*
	case 7:
		newImage = new FlyingBurstCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->setYSpeed(m_random.gen()%2);
		newImage->setPosition(QPoint(xPos,yPos));
		break;
		*/
	default:
		newImage = new FlyingPinkCondomBitmap(m_width,m_height);
		newImage->setXSpeed(-(abs((long)m_random.gen()%5))-3);
		newImage->setYSpeed(m_random.gen()%5);
		newImage->setPosition(QPoint(xPos,yPos));
		counter =0;
		break;
	}
	m_objects.append(newImage);
}
