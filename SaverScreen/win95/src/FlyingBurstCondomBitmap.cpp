/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "FlyingBurstCondomBitmap.h"

//----------------------------------------------------------------------------
FlyingBurstCondomBitmap::FlyingBurstCondomBitmap(int screenWidth, int screenHeight)
:AnimatedObject("explore_condom*.png",screenWidth,screenHeight)
{
//----------------------------------------------------------------------------

}


//----------------------------------------------------------------------------
FlyingBurstCondomBitmap::~FlyingBurstCondomBitmap(){
//----------------------------------------------------------------------------

}



//----------------------------------------------------------------------------
bool FlyingBurstCondomBitmap::move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !moveRel(m_speed);

	if(m_animation->current() ==8)
		m_animation->reset() = 0;
	if(m_currentPosition.x()<=30 && m_currentImage<9){
		m_currentImage=9;
		m_speed.setX(0);
		m_speed.setY(0);
	}

	if(m_currentPosition.y()>=(m_screenHeight) && m_currentImage<9){
		m_currentImage=9;
		m_speed.setX(0);
		m_speed.setY(0);
	}

	if(m_currentImage >  (m_animation->count()-1))
		m_markedForDelete = true;

	return !m_markedForDelete;
}