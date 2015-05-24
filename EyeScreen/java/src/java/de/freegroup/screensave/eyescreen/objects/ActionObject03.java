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

/**
 *
 */
public class ActionObject03 extends ActionObject
{
  public ActionObject03()
  {
    super("action003",1);

    addSuccessor(ActionObject02.class);
    addSuccessor(ActionObject01.class);
    addSuccessor(ActionObject09.class);
  }
  
  public void reInit(Point startPos)
  {
    int xSpeed= -15;

    setXSpeed(xSpeed);

    // determine the end position of the object
    //
    endPosX = startPos.x- (int)((screenWidth)  /getRandom(2,6));
    endPosY = startPos.y+ (int)(((screenHeight) / getRandom(0,20)+getSignum()));

    int steps = (startPos.x - endPosX)/xSpeed;
    if(steps==0)
      setYSpeed(0);
    else
      setYSpeed((startPos.y - endPosY)/steps);
  }
}