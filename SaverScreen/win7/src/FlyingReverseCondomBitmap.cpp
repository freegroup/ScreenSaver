//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingReverseCondomBitmap.cpp 
// Created : 05/28/1999 03:18:16 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingReverseCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingReverseCondomBitmap::CFlyingReverseCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_REVERSE_CONDOM1);
	Insert(IDB_REVERSE_CONDOM2);
	Insert(IDB_REVERSE_CONDOM3);
	Insert(IDB_REVERSE_CONDOM4);
	Insert(IDB_REVERSE_CONDOM5);
	Insert(IDB_REVERSE_CONDOM6);
	Insert(IDB_REVERSE_CONDOM7);
	Insert(IDB_REVERSE_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingReverseCondomBitmap::~CFlyingReverseCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingReverseCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
