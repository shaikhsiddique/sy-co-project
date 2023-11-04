#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main()
{ int x=100,y=100;
int gd=DETECT,gm;
int direction=5;
int position=0;
int position_left=100;
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

 position= 300;
 while (!kbhit())
 {
 cleardevice(); //clear the screen

 // draw waking figure
     // Head
    circle(x+100+direction, y, 40);
    setcolor(4);
    // Body

    rectangle(x+60+direction, y+40, x+140+direction, y+180);
	 setcolor(3);
    // Eyes
    circle(x+75+direction+5, y-20+10, 5);
    circle(x+125+direction-5,y-20+10, 5);
	   setcolor(YELLOW);
    //nose
    line(x+100+direction,y,x+95+direction,y+10);
    line(x+100+direction,y,x+105+direction,y+10);
    line(x+105+direction,y+10,x+95+direction,y+10);

   // mouth

    line(x+direction+110,y+18,x+90+direction,y+18);
    line(x+direction+110,y+25,x+direction+90,y+25);
    line(x+direction+110,y+18,x+direction+110,y+25);
    line(x+direction+90,y+18,x+direction+90,y+25);

    // Arms
    setcolor(4);
    line(x+60+direction, y+60, x+direction, y+120);
    line(x+140+direction, y+60, x+200+direction, y+120);
       setcolor(10);
    // Legs
    line(x+90+direction, y+180, x+60+direction, y+250);
    line(x+110+direction, y+180, x+140+direction, y+250);
       setcolor(4);
    delay(100);
    position=position+direction;
    //x=x+5; //move the robot to right

    //reset the position if the robot goes off the screen
    if (position> getmaxx())
   {
    direction=direction-5;

   }
    else if(position<600)
   {
   position=300;
   direction=direction+5;
   }
    else
   {
    direction=direction+5;
   // position=300;

   }
   }
    closegraph();
    return 0;

    }
