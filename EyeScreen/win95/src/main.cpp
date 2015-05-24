/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include <qapplication.h>
#include "EyeScreenWindow.h"
#include "qfile.h"
#include "qmessagebox.h"
#include "windows.h"

#define APPLICATION_NAME "EyeScreen"

int main( int argc, char** argv )
{
   // do not start the ScreenSaver twice
   //
   if(::FindWindow(NULL,APPLICATION_NAME)!=NULL)
      return 0;


   QApplication app( argc, argv );

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
			EyeScreenWindow *window = new EyeScreenWindow;
   	   window->setCaption(APPLICATION_NAME);
			app.setMainWidget(window);

			window->showMaximized();

			return app.exec();
		}
	}
	else
	{
		EyeScreenWindow *window = new EyeScreenWindow;
  	   window->setCaption(APPLICATION_NAME);
		app.setMainWidget(window);

		window->showMaximized();

		return app.exec();
	}

	return 0;
}

