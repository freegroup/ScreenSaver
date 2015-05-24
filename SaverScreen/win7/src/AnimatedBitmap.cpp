//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : AnimatedBitmap.cpp 
// Created : 05/28/1999 03:17:44 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include <assert.h>
#include "AnimatedBitmap.h"

ranAdd		CAnimatedBitmap::m_random;

//----------------------------------------------------------------------------
CAnimatedBitmap::CAnimatedBitmap(){
//----------------------------------------------------------------------------
	m_markedForDelete = FALSE;
	m_currentImage    = -1;
	m_currentPosition = CPoint(0,0);
}

//----------------------------------------------------------------------------
CAnimatedBitmap::~CAnimatedBitmap(){
//----------------------------------------------------------------------------
	int i=0;

	for(i=0;i<m_drawBitmapCollection.GetSize();i++){
		delete ((CTransparentBitmap*)m_drawBitmapCollection[i]);
	}
	m_drawBitmapCollection.RemoveAll();

}


//----------------------------------------------------------------------------
void CAnimatedBitmap::Insert(UINT DrawResId){
//----------------------------------------------------------------------------
	CTransparentBitmap *newDrawBmp  = new CTransparentBitmap;

	BOOL result = newDrawBmp-> LoadBitmap(DrawResId);

   if(result == TRUE){
	   m_drawBitmapCollection.Add(newDrawBmp);

	   m_currentImage= rand()%m_drawBitmapCollection.GetSize();
   }
}


//----------------------------------------------------------------------------
int CAnimatedBitmap::Height(){
//----------------------------------------------------------------------------
	if(m_currentImage != -1)
		return ((CTransparentBitmap *)m_drawBitmapCollection[m_currentImage])->Height();

	return -1;
}


//----------------------------------------------------------------------------
int CAnimatedBitmap::Width(){
//----------------------------------------------------------------------------
	if(m_currentImage != -1)
		return ((CTransparentBitmap *)m_drawBitmapCollection[m_currentImage])->Width();

	return -1;
}

//----------------------------------------------------------------------------
BOOL CAnimatedBitmap::Move(){
//----------------------------------------------------------------------------
	return MoveRel(m_speed);
}

//----------------------------------------------------------------------------
BOOL CAnimatedBitmap::MoveRel(CPoint offset){
//----------------------------------------------------------------------------

	BOOL result = TRUE;

	if(offset.x < 0){
		m_currentPosition.x += offset.x;
		if(m_currentPosition.x<m_drawRect.left){
			m_currentPosition.x = m_drawRect.right;
			m_currentPosition.y = m_random.gen() % max(1,m_drawRect.Height());
			result = FALSE;
		}
	}
	else{
		m_currentPosition.x += offset.x;
		if(m_currentPosition.x>m_drawRect.right){
			m_currentPosition.x = m_drawRect.left;
			result = FALSE;
		}
	}

	if(offset.y>0){
		m_currentPosition.y += offset.y;
		if(m_currentPosition.y>m_drawRect.bottom){
			m_currentPosition.y = m_drawRect.top;
			result = FALSE;
		}
	}
	else{
		m_currentPosition.y += offset.y;
		if(m_currentPosition.y<m_drawRect.top){
			m_currentPosition.y = m_drawRect.bottom;
			result = FALSE;
		}
	}
	return result;
}


//----------------------------------------------------------------------------
void CAnimatedBitmap::Draw(CDC * pDC, COLORREF cr){
//----------------------------------------------------------------------------
   if(m_currentImage != -1) {
		if(m_currentImage >= m_drawBitmapCollection.GetSize())
			m_currentImage=0;
		((CTransparentBitmap *)m_drawBitmapCollection[m_currentImage])->DrawTransparent(pDC,m_currentPosition,cr);
		m_currentImage++;
	}
}






