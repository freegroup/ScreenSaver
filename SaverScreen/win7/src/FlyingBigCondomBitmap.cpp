//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingBigCondomBitmap.cpp 
// Created : 05/28/1999 03:17:49 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingBigCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingBigCondomBitmap::CFlyingBigCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_BIG_CONDOM1);
	Insert(IDB_BIG_CONDOM2);
	Insert(IDB_BIG_CONDOM3);
	Insert(IDB_BIG_CONDOM4);
	Insert(IDB_BIG_CONDOM5);
	Insert(IDB_BIG_CONDOM6);
	Insert(IDB_BIG_CONDOM7);
	Insert(IDB_BIG_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingBigCondomBitmap::~CFlyingBigCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingBigCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
