/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */


#include"ranAdd.H"
#include<stdlib.h>
#include<time.h>
#include "ProcTrace.h"


//----------------------------------------------------------------------------
ranAdd::ranAdd( int reset ) : n( 23 ), k( 54 ) 
//----------------------------------------------------------------------------
{
    if( reset )
        srand( time( 0 ) );
    for( int i = 0 ; i < 55 ; box[ i++ ] = aran() ); 
}

//----------------------------------------------------------------------------
uint32 ranAdd::gen() 
//----------------------------------------------------------------------------
{
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


//----------------------------------------------------------------------------
uint32 ranAdd::aran() const 
//----------------------------------------------------------------------------
{
    return ( ( (uint32) rand() ) << 16 ) + ( rand() ); 
}
