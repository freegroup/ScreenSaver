#include <qapplication.h>
#include "SaverScreenWindow.h"
#include "qfile.h"
#include "ProcTrace.h"
#include "windows.h"

#define APPLICATION_NAME "SaverScreen"

int main( int argc, char** argv )
{
	QApplication app( argc, argv );

   // Do not start the application twice
   //
   if(::FindWindow(NULL,APPLICATION_NAME)!=NULL)
      return 0;

	if(argc>1)
	{
		if ((strcmp(argv[1],"/c")==0) || (strcmp(argv[1],"/C")==0))
		{
			//	DoConfig;
		}
		else if((strcmp(argv[1],"/p")==0) ||(strcmp(argv[1],"/P")==0))
		{
			// DoSmall();
		}
		else if((strcmp(argv[1],"/s")==0) || (strcmp(argv[1],"/S")==0))
		{
			SaverScreenWindow *window = new SaverScreenWindow;
    	   window->setCaption(APPLICATION_NAME);
			app.setMainWidget(window);

			window->showMaximized();

			return app.exec();
		}
	}
	else
	{
		SaverScreenWindow *window = new SaverScreenWindow;
  	   window->setCaption(APPLICATION_NAME);
		app.setMainWidget(window);

		window->showMaximized();

		return app.exec();
	}

	return 0;
}

