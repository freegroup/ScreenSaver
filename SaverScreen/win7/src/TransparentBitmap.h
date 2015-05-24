#if !defined(AFX_CISBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
#define AFX_CISBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_


class CTransparentBitmap : public CBitmap  
{
public:
	CTransparentBitmap();
	virtual ~CTransparentBitmap();

	int Height();
	int Width();	
	virtual void DrawTransparent(CDC* pDC, CPoint p, COLORREF crColour);	
	virtual BOOL LoadBitmap( UINT nIDResource );
  
	
private:
	COLORREF	m_crBlack;
	COLORREF	m_crWhite;
	CPalette m_palette;
};

#endif // !defined(AFX_CISBITMAP_H__08BA6EB3_DB4C_11D1_8A89_0040052E2D91__INCLUDED_)
