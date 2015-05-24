#include <stdafx.h>
#include "resource.h"	
#include "FlyingRotateCondomBitmap.h"

//----------------------------------------------------------------------------
CFlyingRotateCondomBitmap::CFlyingRotateCondomBitmap(){
//----------------------------------------------------------------------------
	Insert(IDB_ROTATE_CONDOM1);
	Insert(IDB_ROTATE_CONDOM2);
	Insert(IDB_ROTATE_CONDOM3);
	Insert(IDB_ROTATE_CONDOM4);
	Insert(IDB_ROTATE_CONDOM5);
	Insert(IDB_ROTATE_CONDOM6);
	Insert(IDB_ROTATE_CONDOM7);
	Insert(IDB_ROTATE_CONDOM8);
}

//----------------------------------------------------------------------------
CFlyingRotateCondomBitmap::~CFlyingRotateCondomBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
BOOL CFlyingRotateCondomBitmap::Move(){
//----------------------------------------------------------------------------
	m_markedForDelete = !MoveRel(m_speed);
	return !m_markedForDelete;
}
