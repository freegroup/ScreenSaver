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
 * Created on Jun 5, 2004
 *
 */
package de.freegroup.screensave.eyescreen.objects;

import java.awt.Point;
import java.util.*;

/**
 *
 */
public abstract class ActionObject extends AnimatedObject  
{
  int     endPosX;
  int     endPosY;
  long    liveCounter;
  
  List    successors = new ArrayList();
  static Map     cache      = new HashMap();
  private int     selection  = 0;
  
  public ActionObject(String filepattern,int imagesPerFrame)
  {
    super(filepattern, imagesPerFrame);
    liveCounter=-1;
  }

  public final void addSuccessor(Class object)
  {
    successors.add(object);
  }
  
  public final ActionObject  getSuccessor(boolean objectVisible) throws Exception
  {
    if(selection>=successors.size())
      selection=0;
    
    Class clazz = (Class)successors.get(selection++);
    
    ActionObject object=(ActionObject)cache.get(clazz);
    if(object==null)
    {  
      cache.put(clazz,object=(ActionObject)clazz.newInstance());
    }
    object.setPosition(currentPosition);
    object.reInit(currentPosition);
    System.out.println(selection);
    return object;
  }
  
  public abstract void reInit(Point pos);
  
  /**
   * 
   * @param from
   * @param to
   * @return
   */
  public static double getRandom(int from, int to)
  {
    double base= (Math.random()*to)+from;
    return base;
  }
  
  public boolean  move()
  {
	  if(liveCounter>0)
	  {
	    liveCounter--;
	    if (liveCounter==0)
	      return false;
	  }
	  else
	  {
	    if((speed.x>0) && (currentPosition.x>endPosX))
	      return false;
	    if((speed.x<0) && (currentPosition.x<endPosX))
	      return false;
	    if((speed.y>0) && (currentPosition.y>endPosY))
	      return false;
	    if((speed.y<0) && (currentPosition.y<endPosY))
	      return false;
	  }
	  return super.move();
  }
  
  /**
   * 
   */
  public int getYPosition()
  {
    final float xStrech = 3;
    final float yStrech = 3;

    if(speed.x==0)
      return currentPosition.y+1;
    
    double newYPos = Math.abs(Math.sin(currentPosition.x/(xStrech*speed.x)) * (yStrech*speed.x));

    return currentPosition.y+(int)newYPos;
  }
  
  public int getSignum()
  {
    return Math.random()-0.5f>0?-1:1;
  }
}

