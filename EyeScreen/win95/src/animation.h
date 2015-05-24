/**
 * Title:        EyeScreen
 * Description:  Simple ScreenSaver for windows
 * Copyright:    Copyright (c) 2001
 * Company:      FreeGroup     (www.FreeGroup.de)
 * Author:       Andreas Herz  (a.herz@FreeGroup.de)
 * Version:      1.0
 */

#if !defined(AFX_ANIMATION_H__855F2A71_EF7A_11D3_B707_000629C18114__INCLUDED_)
#define AFX_ANIMATION_H__855F2A71_EF7A_11D3_B707_000629C18114__INCLUDED_

#include "qpixmap.h"
#include "qstring.h"
#include "qlist.h"


class Animation  {
public:
	Animation(QString fileprefix , int imagesPerFrame, bool createMask=FALSE);
	virtual ~Animation();

    void      step();
	int       getImageCount();
	int       getFrameCount();
	int       current(){return m_currentImage;};
    QPixmap&  framePixmap();

protected:
    QList<QPixmap>    m_pixmaps;
    QPixmap          *m_currentPixmap;
  	 int               m_currentImage;
    QString           m_filePattern;
    long              m_imagesPerFrame;  // wie oft wird eine Bild gezeigt bevor 
                                         // die Funktion step() wirklich zum nächsten
                                         // Bild schaltet. Man kann so die Animations-
                                         // geschwindigkeit steuern....es wird ein und 
                                         // dasselbe Bild halt öfters gezeigt.
    long              m_imageRepeat;     // wie oft wurde das ein und dasselbe Bild
                                         // schon gezeigt.
};

#endif




