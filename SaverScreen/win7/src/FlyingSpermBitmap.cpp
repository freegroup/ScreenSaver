//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : FlyingSpermBitmap.cpp 
// Created : 05/28/1999 03:18:23 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "resource.h"	
#include "FlyingSpermBitmap.h"

//----------------------------------------------------------------------------
CFlyingSpermBitmap::CFlyingSpermBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_SPERM1);
	Insert(IDB_SPERM2);
	Insert(IDB_SPERM3);
	Insert(IDB_SPERM4);
	Insert(IDB_SPERM5);
	Insert(IDB_SPERM6);
	Insert(IDB_SPERM7);
	Insert(IDB_SPERM8);
}

//----------------------------------------------------------------------------
CFlyingSpermBitmap::~CFlyingSpermBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingSpermBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
