//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingUndichtCondomBitmap.cpp 
// Created : 05/28/1999 03:18:27 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingUndichtCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingUndichtCondomBitmap::CFlyingUndichtCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_UNDICHT_CONDOM1);
	Insert(IDB_UNDICHT_CONDOM2);
	Insert(IDB_UNDICHT_CONDOM3);
	Insert(IDB_UNDICHT_CONDOM4);
	Insert(IDB_UNDICHT_CONDOM5);
	Insert(IDB_UNDICHT_CONDOM6);
	Insert(IDB_UNDICHT_CONDOM7);
	Insert(IDB_UNDICHT_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingUndichtCondomBitmap::~CFlyingUndichtCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingUndichtCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
