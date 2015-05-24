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

/**
 * Simple screen saver based on the screenSaver SDK from Mark Roth
 * The SDKis available at https://screensavers.dev.java.net/
 * 
 * Created on Jun 5, 2004
 * 
 * @author Andreas Herz
 **/
package de.freegroup.screensave.eyescreen;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;

import org.jdesktop.jdic.screensaver.SimpleScreensaver;

import de.freegroup.screensave.eyescreen.objects.ActionObject;
import de.freegroup.screensave.eyescreen.objects.ActionObject01;
import de.freegroup.screensave.eyescreen.objects.Animation;

/**
 *
 */
public class EyeScreen  extends SimpleScreensaver
{
  boolean debug=false;
  
  /** Off-screen image for double-buffering */
  private Image    offScreen         = null;
  private Graphics offScreenGraphics = null;
  
  private ActionObject currentAnim = null;
  private String       lastException="";
  
  /* 
   * @see org.jdesktop.jdic.screensaver.SimpleScreensaver#paint(java.awt.Graphics)
   */
  public void paint(Graphics realG)
  {
    
    Component c = getContext().getComponent();
    if( (offScreen == null) || (offScreen.getWidth(null) != c.getWidth()) ||(offScreen.getHeight(null) != c.getHeight()) ) 
    {
      ActionObject.screenHeight = c.getHeight()-150;
      ActionObject.screenWidth  = c.getWidth()-150;
      currentAnim =new ActionObject01();
      int startX=(int)ActionObject.getRandom(0,c.getWidth()/2);
      int startY=(int)ActionObject.getRandom(0,c.getHeight()/2);
      Point startPos = new Point(startX,startY);
      currentAnim.setPosition(startPos);
      currentAnim.reInit(startPos);
      if( offScreen != null ) 
      {
        offScreenGraphics.dispose();
      }
      offScreen = c.createImage( c.getWidth(), c.getHeight() );
      offScreenGraphics = offScreen.getGraphics();
    }
    Graphics g = offScreenGraphics;
    Graphics2D g2D = (Graphics2D)g;
    
   
    try
    {
      g.setColor( Color.black );
      g.fillRect( 0, 0, c.getWidth(), c.getHeight() );
     
      int x =currentAnim.getXPosition()+currentAnim.getImageOffset().x;
      int y =currentAnim.getYPosition()+currentAnim.getImageOffset().y;
      g.drawImage(currentAnim.framePixmap(),x,y,null);
	    if(debug)
	    {  
	      g.setColor( Color.blue );
	      g2D.drawString("Position:"+x+":"+y,10,10);
	      g2D.drawString("Signum:"+currentAnim.getSignum(),10,30);
	      g2D.drawString("Class:"+currentAnim.getClass().getName(),10,50);
	      g2D.drawString("Exception:"+lastException,10,70);
	      g2D.drawString(""+System.currentTimeMillis(),200,10);
	    }
	    if(currentAnim.move()==false)
      currentAnim=currentAnim.getSuccessor(true);
    }
		catch (Throwable e)
		{
		  // ohoh....switch to debug and show the error on the screen
		  debug=true;
		  lastException=e.toString() +" in class:"+currentAnim.getClass().getName();
		}
		// Blit frame:
		realG.drawImage( offScreen, 0, 0, null );
  }

  
  /**
   * Only to test this class!
   * 
   * @param args
   */
  public static void main(String[] args)
  {
    try
    {
      EyeScreen screen = new EyeScreen();
      
      screen.currentAnim=new ActionObject01();
      for(int i=0;i<1000;i++)
      {
        screen.currentAnim =screen.currentAnim.getSuccessor(true);
        System.out.println(screen.currentAnim);
        System.out.println(screen.currentAnim.getClass().getName());
      }
      System.out.println(screen.currentAnim.getXPosition());
      System.out.println(screen.currentAnim.getYPosition());
    }
    catch (Exception e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
    
  }


}
