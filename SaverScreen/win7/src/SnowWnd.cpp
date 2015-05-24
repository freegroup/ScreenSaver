//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : SnowWnd.cpp 
// Created : 05/28/1999 03:17:23 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "snowss.h"
#include "SnowWnd.h"
#include "TransparentBitmap.h"
#include "FlyingCondomBitmap.h"
#include "FlyingCondom2Bitmap.h"
#include "FlyingReverseCondomBitmap.h"
#include "FlyingUndichtCondomBitmap.h"
#include "FlyingRotateCondomBitmap.h"
#include "FlyingBigCondomBitmap.h"
#include "FlyingRaketeCondomBitmap.h"
#include "FlyingSpermBitmap.h"
#include "FlyingEarthBitmap.h"
#include "FlyingBurstCondomBitmap.h"
#include "ranAdd.H"


/////////////////////////////////////////////////////////////////////////////
// CSnowWnd

BEGIN_MESSAGE_MAP(CFullCondomWnd,CFullWnd)
	//{{AFX_MSG_MAP(CFullCondomWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



//----------------------------------------------------------------------------
CFullCondomWnd::CFullCondomWnd(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
void CFullCondomWnd::InsertNewObject(){
//----------------------------------------------------------------------------

   static long counter = 7;
	long xPos=0;
	long yPos=0;
	CAnimatedBitmap *newImage=NULL;

	CRect rc;
	GetClientRect(rc);
	rc.InflateRect(100,0,0,0);

	xPos = rc.Width();
	yPos = m_random.gen()% max(1,rc.Height()-100);

	switch(counter++){
	case 0:
		newImage = new CFlyingRaketeCondomBitmap;
		newImage->SetXSpeed(-14);
		newImage->SetYSpeed(0);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 1:
		newImage = new CFlyingBigCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%8))-3);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 2:
		newImage = new CFlyingRotateCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%8))-3);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 3:
		newImage = new CFlyingUndichtCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%8))-3);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 4:
		newImage = new CFlyingReverseCondomBitmap;
		newImage->SetXSpeed((abs((long)m_random.gen()%10))+20);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(-10,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 5:
		newImage = new CFlyingSpermBitmap;
		newImage->SetXSpeed((abs((long)m_random.gen()%10))+20);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(-10,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 6:
		newImage = new CFlyingEarthBitmap;
		newImage->SetXSpeed(1);
		newImage->SetYSpeed(0);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(-10,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 7:
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
	   xPos = rc.Width();
	   yPos = m_random.gen()% max(1,rc.Height()-100);
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
	   xPos = rc.Width();
	   yPos = m_random.gen()% max(1,rc.Height()-100);
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
	   xPos = rc.Width();
	   yPos = m_random.gen()% max(1,rc.Height()-100);
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
	   xPos = rc.Width();
	   yPos = m_random.gen()% max(1,rc.Height()-100);
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
	   xPos = rc.Width();
	   yPos = m_random.gen()% max(1,rc.Height()-100);
		break;
	case 8:
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 9:
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	case 10:
		newImage = new CFlyingBurstCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%4))-10);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		break;
	default:
		newImage = new CFlyingPinkCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%8))-3);
		newImage->SetYSpeed(m_random.gen()%5);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(xPos,yPos));
   	m_aniImageCollection.InsertAt(0,newImage);
		counter =0;
		break;
	}
}


//----------------------------------------------------------------------------
void CFullCondomWnd::UpdateScreen(void){
//----------------------------------------------------------------------------
	static long randomCounter = 0;

   CClientDC dc(this);

	CDC memDC ;
	CBitmap memBitmap ;
	CBitmap* oldBitmap ; 
	CRect rc;
	GetClientRect(rc);

   
	// to avoid flicker, establish a memory dc, draw to it 
	// and then BitBlt it to the client
	memDC.CreateCompatibleDC(&dc) ;
	memBitmap.CreateCompatibleBitmap(&dc, rc.Width(), rc.Height()) ;
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap) ;

	if (memDC.GetSafeHdc() != NULL){
		int i=0;


		for(i=0;i<m_aniImageCollection.GetSize();i++){
			((CAnimatedBitmap*)m_aniImageCollection[i])->Move();
         ((CAnimatedBitmap*)m_aniImageCollection[i])->Draw(&memDC);
			if(((CAnimatedBitmap*)m_aniImageCollection[i])->IsMarkedForDelete()){
				delete ((CAnimatedBitmap*)m_aniImageCollection[i]);
				m_aniImageCollection.RemoveAt(i);
			}
		}
		// finally send the result to the display
		dc.BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY) ;
	}
	memDC.SelectObject(oldBitmap);
	if(randomCounter == 0 ){
		InsertNewObject();
		randomCounter = abs(m_random.gen()%100)+5;
	}

	if(randomCounter >0)
		randomCounter--;
      
}


//----------------------------------------------------------------------------
int CFullCondomWnd::OnCreate(LPCREATESTRUCT lpCreateStruct){
//----------------------------------------------------------------------------

   if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	long   count = AfxGetApp()->GetProfileInt("Options","Count",10);
	int    i;
	CRect  rc;

	GetClientRect(rc);
	CAnimatedBitmap *newImage;

	rc.InflateRect(100,100,100,100);
	for( i=0;i<count;i++){
		newImage = new CFlyingCondomBitmap;
		newImage->SetXSpeed(-(abs((long)m_random.gen()%8))-2);
		newImage->SetYSpeed(m_random.gen()%2);
		newImage->SetDrawRect(rc);
		newImage->SetPosition(CPoint(m_random.gen()% max(1,rc.Width()),m_random.gen()% max(1,rc.Height())));
		m_aniImageCollection.Add(newImage);
	}

	if(m_uTimeTick)
		SetTimer(1,m_uTimeTick,NULL);

	return 0;
}

//----------------------------------------------------------------------------
void CFullCondomWnd::OnPaint() {
//----------------------------------------------------------------------------
	CPaintDC dc(this); 
	
	// Do not call CWnd::OnPaint() for painting messages
	CRect rc;
	GetClientRect(rc);
	CBrush brush;

	brush.CreateSolidBrush(RGB(0,0,0));
	dc.FillRect(rc,&brush);
}
