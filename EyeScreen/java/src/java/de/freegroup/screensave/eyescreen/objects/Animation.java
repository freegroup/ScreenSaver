// Copyright © 2004  Andreas Herz. All rights reserved. Use is
// subject to license terms.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA


/*
 * Created on Jun 4, 2004
 *
 */
package de.freegroup.screensave.eyescreen.objects;

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

/**
 * Simple class to handle a sequenze of images.
 * 
 * 
 */
public class Animation
{
  public static String error="";
  protected  List            images;
  protected  Image           currentImage;
  protected  int             currentImageIndex;

  long       imagesPerFrame; 	// wie oft wird eine Bild gezeigt bevor 
                              // die Funktion step() wirklich zum nächsten
                              // Bild schaltet. Man kann so die Animations-
                              // geschwindigkeit steuern....es wird ein und 
                              // dasselbe Bild halt öfters gezeigt.
  
  long       imageRepeat;    	// wie oft wurde das ein und dasselbe Bild
                              // schon gezeigt.
  
  Animation(String fileprefix , int imagesPerFrame)
  {
    try
    {
      this.imagesPerFrame = imagesPerFrame;
      this.imageRepeat    = 0;
      this.currentImageIndex   = 0;
      this.images =new ArrayList();
      for(int i =1; ;i++)
      {
        InputStream input=getClass().getResourceAsStream("/de/freegroup/screensave/eyescreen/images/"+fileprefix+"_"+i+".png");
	      if(input==null)
	        break;
	      images.add(ImageIO.read( input));
	      input.close();
      }
    }
    catch (Exception e)
    {
      // TODO Auto-generated catch block
      error=e.toString();
      e.printStackTrace();
    }
    }

    public void   step()
    {
      if(++imageRepeat> imagesPerFrame)
      {
        imageRepeat=0;
        currentImageIndex++;
        if(currentImageIndex>= images.size())
        {
          currentImageIndex=0;
        }
      }
    }
    
    public int  getImageCount()
    {
      return images.size();
    }
    
    public int getFrameCount()
    {
      return (int)(images.size()*imagesPerFrame);
    }
    
    public int  current()
    {
      	return currentImageIndex;
    }
    
    public Image  framePixmap()
    {
      return (BufferedImage)images.get(currentImageIndex);
    }
}
