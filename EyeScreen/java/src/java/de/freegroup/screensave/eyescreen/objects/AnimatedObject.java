// Copyright © 2004 Andreas Herz. All rights reserved. Use is
// subject to license terms.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
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
import java.awt.Point;

/**
 *  
 */
public class AnimatedObject
{
  static public int screenHeight;
  static public int screenWidth;

  protected Point currentPosition;
  protected Point speed;
  protected Animation m_animation;

  Point imageOffset;

  AnimatedObject(String filepattern, int imagesPerFrame)
  {
    m_animation = new Animation(filepattern, imagesPerFrame);
    imageOffset = new Point(0, 0);
    speed = new Point(1, 1);
    currentPosition = new Point(10, 10);
  }

  /**
   * @param x
   */
  public void setXSpeed(int x)
  {
    speed.x = x;
  }

  /**
   * @param y
   */
  public void setYSpeed(int y)
  {
    speed.y = y;
  }

  /**
   * @param p
   */
  public void setPosition(Point p)
  {
    currentPosition = new Point(p);
  }

  /**
   * @return
   */
  public int getXPosition()
  {
    return currentPosition.x;
  }

  /**
   * @return
   */
  public int getYPosition()
  {
    return currentPosition.y;
  }

  /**
   * @param offset
   * @return
   */
  public boolean moveRel(Point offset)
  {
    boolean result = true;

    m_animation.step();

    currentPosition.translate(offset.x, offset.y);
    if (offset.x < 0)
    {
      if (currentPosition.x < (-100))
      {
        result = false;
      }
    }
    else
    {
      if (currentPosition.x > (screenWidth + 100))
      {
        result = false;
      }
    }

    if (offset.y > 0)
    {
      if (currentPosition.y > (screenHeight + 100))
      {
        result = false;
      }
    }
    else
    {
      if (currentPosition.y < (-100))
      {
        result = false;
      }
    }
    return result;
  }

  /**
   * @return
   */
  public boolean move()
  {
    return moveRel(speed);
  }

  /**
   * @return
   */
  public int getImageCount()
  {
    return m_animation.getImageCount();
  }

  /**
   * @return
   */
  public int getFrameCount()
  {
    return m_animation.getFrameCount();
  }

  /**
   * @return
   */
  public Image framePixmap()
  {
    return m_animation.framePixmap();
  }

  /**
   * @return Returns the imageOffset.
   */
  public Point getImageOffset()
  {
    return imageOffset;
  }

  /**
   * @param imageOffset
   *          The imageOffset to set.
   */
  public void setImageOffset(Point imageOffset)
  {
    this.imageOffset = new Point(imageOffset);
  }

};
