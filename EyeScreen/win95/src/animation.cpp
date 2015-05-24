/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#include "qdir.h"
#include "qarray.h"
#include "animation.h"
#include "qbitmap.h"
#include "assert.h"
#include "windows.h"

//----------------------------------------------------------------------------
Animation::Animation(QString filepattern, int imagesPerFrame, bool createMask){
//----------------------------------------------------------------------------

   char lpFilename[500];
   char drive[_MAX_DRIVE];
   char dir[_MAX_DIR];
   char fname[_MAX_FNAME];
   char ext[_MAX_EXT];



	m_pixmaps.setAutoDelete(true);

	::GetModuleFileName( ::GetModuleHandle(NULL),(char*) lpFilename, (DWORD)sizeof(lpFilename));
   _splitpath( (const char*)lpFilename, drive, dir, fname, ext );
   QString applicationPath = QString(drive) + dir;

   QDir d(applicationPath +"/images/");
   d.setFilter( QDir::Files | QDir::Hidden | QDir::NoSymLinks );
   d.setNameFilter( filepattern.data());
   
   const QFileInfoList *list = d.entryInfoList();
   QFileInfoListIterator it( *list );      // create list iterator
   QFileInfo *fi;                          // pointer for traversing
   
   while ( (fi=it.current()) ) 
   {
	  QString filename = applicationPath +QString("/images/")+fi->fileName();
      QPixmap *p;
      p = new QPixmap(filename);
      m_pixmaps.append(p);
      ++it;                               // goto next list element
   }

   // create a bitmask if required
   //
   if(createMask)
   {
      QPixmap * pm;
      for(pm=m_pixmaps.first(); pm != 0; pm = m_pixmaps.next())
	  {
         pm->setMask( pm->createHeuristicMask());
      }
   }

   m_currentPixmap  = m_pixmaps.first();
   m_imagesPerFrame = imagesPerFrame;
   m_filePattern    = filepattern;
   m_imageRepeat    = 0;
   m_currentImage   = 0;
   assert(m_currentPixmap != NULL);
}

//----------------------------------------------------------------------------
Animation::~Animation(){
//----------------------------------------------------------------------------

   m_pixmaps.clear();
}

//----------------------------------------------------------------------------
int Animation::getImageCount()
//----------------------------------------------------------------------------
{
	return m_pixmaps.count();
}

//----------------------------------------------------------------------------
int Animation::getFrameCount()
//----------------------------------------------------------------------------
{
	return m_pixmaps.count()*m_imagesPerFrame;
}

//----------------------------------------------------------------------------
void Animation::step(){
//----------------------------------------------------------------------------
 
   if(++m_imageRepeat> m_imagesPerFrame)
   {
      m_imageRepeat=0;
	  m_currentImage++;
      m_currentPixmap = m_pixmaps.next();
      if(m_currentPixmap == NULL)
	  {
		 m_currentImage=0;
		 m_currentPixmap = m_pixmaps.first();
	  }
   }
   assert(m_currentPixmap != NULL);
}

//----------------------------------------------------------------------------
QPixmap& Animation::framePixmap(){
//----------------------------------------------------------------------------
   
   assert(m_currentPixmap != NULL);
   return *m_currentPixmap;
}
