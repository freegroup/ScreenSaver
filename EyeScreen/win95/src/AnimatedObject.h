/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ANIMATEDBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_ANIMATEDBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_

#include "ranAdd.H"
#include "qpoint.h"
#include "qrect.h"
#include "Animation.h"

class AnimatedObject 
{
public:
	AnimatedObject(QString filepattern,int imagesPerFrame, int screenWidth, int screenHeight, QPoint startPos);
	virtual ~AnimatedObject();


	virtual void setXSpeed(int x){m_speed.setX(x);};
	virtual void setYSpeed(int y){m_speed.setY(y);};
	virtual void setPosition(QPoint p)
	{
			m_currentPosition.setX(p.x());
			m_currentPosition.setY(p.y());
	};

	virtual int  getXPosition(){ return m_currentPosition.x();};
	virtual int  getYPosition(){ return m_currentPosition.y();};

	virtual bool moveRel(QPoint offset);
	virtual bool move();
	virtual int  getImageCount();
	virtual int  getFrameCount();
    QPixmap&     framePixmap();

protected:
	QPoint      m_currentPosition;
    QPoint      m_speed;
	int         m_screenHeight;
	int         m_screenWidth;
	Animation  *m_animation;

    static ranAdd		m_random;
};

#endif // !defined(AFX_CISBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
