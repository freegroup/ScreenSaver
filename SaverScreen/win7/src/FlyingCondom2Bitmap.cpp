//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingCondom2Bitmap.cpp 
// Created : 05/28/1999 03:17:59 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingCondom2Bitmap.h"

//----------------------------------------------------------------------------
CFlyingPinkCondomBitmap::CFlyingPinkCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_PINK_CONDOM1);
	Insert(IDB_PINK_CONDOM2);
	Insert(IDB_PINK_CONDOM3);
	Insert(IDB_PINK_CONDOM4);
	Insert(IDB_PINK_CONDOM5);
	Insert(IDB_PINK_CONDOM6);
	Insert(IDB_PINK_CONDOM7);
	Insert(IDB_PINK_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingPinkCondomBitmap::~CFlyingPinkCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingPinkCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
