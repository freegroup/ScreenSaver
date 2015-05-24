//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : ranadd.cpp 
// Created : 05/28/1999 03:18:50 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include"ranAdd.H"
#include<stdlib.h>
#include<time.h>


ranAdd::ranAdd( int reset ) : n( 23 ), k( 54 ) {
    if( reset )
        srand( time( 0 ) );
    for( int i = 0 ; i < 55 ; box[ i++ ] = aran() ); 
}

uint32 ranAdd::gen() {
    uint32 v( box[ n ] + box[ k ] );
    if( ! n )
        n = 54;
    else
        --n;
    box[ k ] = v;
    if( ! k )
        k = 54;
    else
        --k;
    return v; 
}


uint32 ranAdd::aran() const {
    return ( ( (uint32) rand() ) << 16 ) + ( rand() ); 
}
