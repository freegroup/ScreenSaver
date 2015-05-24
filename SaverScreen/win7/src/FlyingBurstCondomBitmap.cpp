//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingBurstCondomBitmap.cpp 
// Created : 05/28/1999 03:17:54 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingBurstCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingBurstCondomBitmap::CFlyingBurstCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_CONDOM1);
	Insert(IDB_CONDOM2);
	Insert(IDB_CONDOM3);
	Insert(IDB_CONDOM4);
	Insert(IDB_CONDOM5);
	Insert(IDB_CONDOM6);
	Insert(IDB_CONDOM7);
	Insert(IDB_CONDOM8);
	Insert(IDB_EX_CONDOM01);
//	Insert(IDB_EX_CONDOM02);
	Insert(IDB_EX_CONDOM03);
//	Insert(IDB_EX_CONDOM04);
	Insert(IDB_EX_CONDOM05);
//	Insert(IDB_EX_CONDOM06);
	Insert(IDB_EX_CONDOM07);
//	Insert(IDB_EX_CONDOM08);
	Insert(IDB_EX_CONDOM09);
//	Insert(IDB_EX_CONDOM10);
	Insert(IDB_EX_CONDOM11);
//	Insert(IDB_EX_CONDOM12);
	Insert(IDB_EX_CONDOM13);
//	Insert(IDB_EX_CONDOM14);
	Insert(IDB_EX_CONDOM15);
//	Insert(IDB_EX_CONDOM16);

}

//----------------------------------------------------------------------------
CFlyingBurstCondomBitmap::~CFlyingBurstCondomBitmap(){
//----------------------------------------------------------------------------

}



//----------------------------------------------------------------------------
BOOL CFlyingBurstCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	if(m_currentImage ==8)
		m_currentImage = 0;
	if(m_currentPosition.x<=10 && m_currentImage<9){
		m_currentImage=9;
		m_speed.x = 0;
		m_speed.y = 0;
	}

	if(m_currentPosition.y>=(m_drawRect.Height()-Height()) && m_currentImage<9){
		m_currentImage=9;
		m_speed.x = 0;
		m_speed.y = 0;
	}

	if(m_currentImage ==  (m_drawBitmapCollection.GetSize()-1))
		m_markedForDelete = TRUE;

	return !m_markedForDelete;
}