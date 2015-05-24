
#include "ssbase.h"
#include "ShowWnd.h"
#include "SnowWnd.h"


#include "resource.h"	

class CCondomScreenSaverApp : public CSSApp{

public:
	CCondomScreenSaverApp();

	virtual BOOL InitInstance();
	virtual BOOL DoConfig(void);

	
	virtual CSmallWnd* GetSmallWindow(){ return new CSmallCondomWnd;};
	virtual CFullWnd*  GetFullWindow() { return new CFullCondomWnd;};
};


/////////////////////////////////////////////////////////////////////////////
