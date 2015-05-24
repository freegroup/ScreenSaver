/**
 * Title:        SaverScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#ifndef _RANADD_H
#define _RANADD_H

#ifndef uint32
typedef unsigned long uint32;
#endif



class ranAdd {
  public:
    ranAdd( int reset = 1 );

    uint32 gen();

  private:
    uint32 aran() const;
    int n,
        k;
    uint32 box[ 55 ];
};

#endif  // _RANADD_H
