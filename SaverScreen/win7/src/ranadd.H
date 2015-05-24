// File ranAdd.H
// created by Philip Staite
// 13:01:34 Tue Mar 12 1996

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
