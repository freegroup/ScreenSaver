//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : ShowWnd.cpp 
// Created : 05/28/1999 03:19:02 PM
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


BEGIN_MESSAGE_MAP(CSmallCondomWnd,CSmallWnd)
	//{{AFX_MSG_MAP(CSmallCondomWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//----------------------------------------------------------------------------
CSmallCondomWnd::CSmallCondomWnd(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
CSmallCondomWnd::~CSmallCondomWnd(){
//----------------------------------------------------------------------------
}


//----------------------------------------------------------------------------
int CSmallCondomWnd::OnCreate(LPCREATESTRUCT lpCreateStruct){
//----------------------------------------------------------------------------
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
void CSmallCondomWnd::UpdateScreen(){
//----------------------------------------------------------------------------
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

		int i;

		for(i=0;i<m_aniImageCollection.GetSize();i++){
			((CAnimatedBitmap*)m_aniImageCollection[i])->Move();
			((CAnimatedBitmap*)m_aniImageCollection[i])->Draw(&memDC);
		}
		// finally send the result to the display
		dc.BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY) ;
	}
	memDC.SelectObject(oldBitmap) ;
}


//----------------------------------------------------------------------------
void CSmallCondomWnd::OnPaint() {
//----------------------------------------------------------------------------
	CPaintDC dc(this); 
	
	// Do not call CWnd::OnPaint() for painting messages
	CRect rc;
	GetClientRect(rc);
	CBrush brush;

	brush.CreateSolidBrush(RGB(0,0,0));
	dc.FillRect(rc,&brush);
}
