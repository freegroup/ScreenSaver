//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingRaketeCondomBitmap.cpp 
// Created : 05/28/1999 03:18:11 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingRaketeCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingRaketeCondomBitmap::CFlyingRaketeCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_RAKETE_CONDOM1);
	Insert(IDB_RAKETE_CONDOM2);
	Insert(IDB_RAKETE_CONDOM3);
	Insert(IDB_RAKETE_CONDOM4);
	Insert(IDB_RAKETE_CONDOM5);
	Insert(IDB_RAKETE_CONDOM6);
	Insert(IDB_RAKETE_CONDOM7);
	Insert(IDB_RAKETE_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingRaketeCondomBitmap::~CFlyingRaketeCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingRaketeCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
