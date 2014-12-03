/*
  MeggyJr_Moving_Dot.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
  int x = 3;
  int y = 3;
  int z = 2;
  int current_x = 0;
  int current_y = 0;
  int xcheck = 7;
  int ycheck = 7;
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup(); 
  DrawPx(3,3,1);
  // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  CheckButtonsPress();
  if(Button_Left)
    if (x>0)
      if (ReadPx (x-1,y) == Red)
        
      drawDot();
      else
        x = x-1;
        drawDot();
  if(Button_Right)
    if (x<7)
       if (ReadPx (x+1,y) == Red)
        
      drawDot();
      else
        x = x+1;
        drawDot();
     
  if(Button_Up)
    if (y<7)
       if (ReadPx (x,y+1) == Red)
        
        drawDot();
      else
        y = y+1;
        drawDot();
  if(Button_Down)
    if (y>0)
      if (ReadPx (x,y-1) == Red)
        drawDot();
      else
        y = y-1;
        drawDot();
  if(Button_B)
    if (z<7)
      z = z +1;
      drawDot();
  if(Button_B)
    if (z == 7)
      z = 1;
      drawDot();
  
      

delay(100);
   //initiator goes here
   // random x goes here
}
 
void drawDot()
{
  
  DrawPx(current_x,current_y,0);
  
  DrawPx(x,y,z);
  current_x = x;
  current_y = y;
   for(int wall_x = 1;wall_x <7;wall_x ++)
    {
    DrawPx(wall_x,4,Red);
    }
    particle_generator();
moveenemies();
if (ReadPx(current_x, current_y) == Green);
  delay(10000000);
  DisplaySlate();
  
}
void particle_generator()
{
  int startx = random(0,8);
  DrawPx(startx,0, Red);
  DisplaySlate();
}
void moveenemies()
{
  for(int ycheck=7;ycheck>0;y--)
  {
    
    for(int xcheck=0;xcheck<8;x++);
    {
    if (ReadPx(xcheck,ycheck) == Green);
      {
        DrawPx(xcheck,ycheck,0);
       DrawPx( xcheck,ycheck +1, Green);
      }
    }
  }
}
/*class Enemy
{ I tried using classes. It didn't work.
  private:
    Enemy(int pin);
    int enemyx = 0
    
    void movement();
 
    
};
void Enemy::movement()
{
  DrawPx(enemyx,enemyy,0
  enemyy = enemyy+1
  DrawPx (enemyx,enemyy,1)
  */
