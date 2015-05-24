//////////////////////////////////////////////////////////////////////////////
//
// FreeGroup Source
// Andreas Herz
// 
// ©  1999 FreeGroup www.FreeGroup.de
//
// File    : TransparentBitmap.cpp 
// Created : 05/28/1999 03:19:35 PM
//
// Compiler: VC 5.0
// System  : Win95/Win98/NT 4.0
//
//////////////////////////////////////////////////////////////////////////////
#include <stdafx.h>
#include "TransparentBitmap.h"


//----------------------------------------------------------------------------
CTransparentBitmap::CTransparentBitmap(){
//----------------------------------------------------------------------------
	m_crBlack = 0;
	m_crWhite = RGB(255,255,255);
}

//----------------------------------------------------------------------------
CTransparentBitmap::~CTransparentBitmap(){
//----------------------------------------------------------------------------

}

//----------------------------------------------------------------------------
int CTransparentBitmap::Width(){
//----------------------------------------------------------------------------
	BITMAP bm;
	GetBitmap(&bm);
	return bm.bmWidth;
}

//----------------------------------------------------------------------------
int CTransparentBitmap::Height(){
//----------------------------------------------------------------------------
	BITMAP bm;
	GetBitmap(&bm);
	return bm.bmHeight;
}


//----------------------------------------------------------------------------
BOOL CTransparentBitmap::LoadBitmap( UINT nIDResource ){
//----------------------------------------------------------------------------
	LPCTSTR lpszResourceName = (LPCTSTR)nIDResource;
	HBITMAP hBmp = (HBITMAP)::LoadImage( AfxGetInstanceHandle(), 
					lpszResourceName, IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION );

   if( hBmp == NULL ) {
			return FALSE;
   }

	Attach( hBmp );

	// Create a logical palette for the bitmap
	DIBSECTION ds;
	BITMAPINFOHEADER &bmInfo = ds.dsBmih;
	GetObject( sizeof(ds), &ds );

	int nColors = bmInfo.biClrUsed ? bmInfo.biClrUsed : 1 << bmInfo.biBitCount;

	// Create a halftone palette if colors > 256. 
	CClientDC dc(NULL);                     // Desktop DC
	if( nColors > 256 )
			m_palette.CreateHalftonePalette( &dc );
	else
	{
			// Create the palette

			RGBQUAD *pRGB = new RGBQUAD[nColors];
			CDC memDC;
			memDC.CreateCompatibleDC(&dc);

			memDC.SelectObject( this );
			::GetDIBColorTable( memDC, 0, nColors, pRGB );

			UINT nSize = sizeof(LOGPALETTE) + (sizeof(PALETTEENTRY) * nColors);
			LOGPALETTE *pLP = (LOGPALETTE *) new BYTE[nSize];

			pLP->palVersion = 0x300;
			pLP->palNumEntries = nColors;

			for( int i=0; i < nColors; i++)
			{
					pLP->palPalEntry[i].peRed = pRGB[i].rgbRed;
					pLP->palPalEntry[i].peGreen = pRGB[i].rgbGreen;
					pLP->palPalEntry[i].peBlue = pRGB[i].rgbBlue;
					pLP->palPalEntry[i].peFlags = 0;
			}

			m_palette.CreatePalette( pLP );

			delete[] pLP;
			delete[] pRGB;
	}

	return TRUE;
}


//----------------------------------------------------------------------------
void CTransparentBitmap::DrawTransparent(CDC * pDC, CPoint p, COLORREF crColor){
//----------------------------------------------------------------------------
   
   COLORREF crOldBack = pDC->SetBkColor(m_crWhite);
	COLORREF crOldText = pDC->SetTextColor(m_crBlack);
	CDC dcImage, dcTrans;

	// Create two memory dcs for the image and the mask
	dcImage.CreateCompatibleDC(pDC);
	dcTrans.CreateCompatibleDC(pDC);

	// Select the image into the appropriate dc
	CBitmap* pOldBitmapImage = dcImage.SelectObject(this);

	// Create the mask bitmap
	CBitmap bitmapTrans;
	int nWidth = Width();
	int nHeight = Height();
	bitmapTrans.CreateBitmap(nWidth, nHeight, 1, 1, NULL);

	// Select the mask bitmap into the appropriate dc
	CBitmap* pOldBitmapTrans = dcTrans.SelectObject(&bitmapTrans);

	// Build mask based on transparent colour
	dcImage.SetBkColor(crColor);
	dcTrans.BitBlt(0, 0, nWidth, nHeight, &dcImage, 0, 0, SRCCOPY);

	// Do the work - True Mask method - cool if not actual display
	pDC->BitBlt(p.x, p.y, nWidth, nHeight, &dcImage, 0, 0, SRCINVERT);
	pDC->BitBlt(p.x, p.y, nWidth, nHeight, &dcTrans, 0, 0, SRCAND);
	pDC->BitBlt(p.x, p.y, nWidth, nHeight, &dcImage, 0, 0, SRCINVERT);

	// Restore settings
	dcImage.SelectObject(pOldBitmapImage);
	dcTrans.SelectObject(pOldBitmapTrans);
	pDC->SetBkColor(crOldBack);
	pDC->SetTextColor(crOldText);
}
