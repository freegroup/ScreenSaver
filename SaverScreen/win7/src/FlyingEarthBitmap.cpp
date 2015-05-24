//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingEarthBitmap.cpp 
// Created : 05/28/1999 03:18:07 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingEarthBitmap.h"

//----------------------------------------------------------------------------
CFlyingEarthBitmap::CFlyingEarthBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_EARTH01);
	Insert(IDB_EARTH02);
	Insert(IDB_EARTH03);
	Insert(IDB_EARTH04);
	Insert(IDB_EARTH05);
	Insert(IDB_EARTH06);
	Insert(IDB_EARTH07);
	Insert(IDB_EARTH08);
	Insert(IDB_EARTH09);
	Insert(IDB_EARTH10);
	Insert(IDB_EARTH11);
	Insert(IDB_EARTH12);
	Insert(IDB_EARTH13);
	Insert(IDB_EARTH14);
	Insert(IDB_EARTH15);
	Insert(IDB_EARTH16);
	Insert(IDB_EARTH17);
	Insert(IDB_EARTH18);
	Insert(IDB_EARTH19);
	Insert(IDB_EARTH20);
	Insert(IDB_EARTH21);
	Insert(IDB_EARTH22);
	Insert(IDB_EARTH23);
	Insert(IDB_EARTH24);
	Insert(IDB_EARTH25);
	Insert(IDB_EARTH26);
	Insert(IDB_EARTH27);
	Insert(IDB_EARTH28);
	Insert(IDB_EARTH29);
	Insert(IDB_EARTH30);
	Insert(IDB_EARTH31);
	Insert(IDB_EARTH32);
	Insert(IDB_EARTH33);
	Insert(IDB_EARTH34);
	Insert(IDB_EARTH35);
	Insert(IDB_EARTH36);
}

//----------------------------------------------------------------------------
CFlyingEarthBitmap::~CFlyingEarthBitmap(){
//----------------------------------------------------------------------------

}



//----------------------------------------------------------------------------
BOOL CFlyingEarthBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
