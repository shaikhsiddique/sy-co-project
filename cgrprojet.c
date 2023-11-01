#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

#define MAX_FISH 5
#define MAX_CREATURES 1
#define MAX_BUBBLES 20

struct Fish {
    int x, y;
    int speed;
    int direction; // 1 for right, -1 for left
    int angle;
    int frame; // Used for animation frames
};

struct SeaCreature {
    int x, y;
    int speed;
    int direction; // 1 for right, -1 for left
    int angle;
    int color; // Add a color attribute for sea creatures
};

//int tail[8];
int i;
 struct Fish fish;
 struct SeaCreature creatures[MAX_CREATURES];
 struct SeaCreature creatures2[MAX_CREATURES];
 struct Fish fishes[5];
 int plant_x = 300, plant_y = 300;
 int bubble_x[MAX_BUBBLES], bubble_y[MAX_BUBBLES];
 int gx=40,gy=470;
 int x,y;
 void boundary_fill(int x,int y,int f_color,int b_color)
 {
 if(getpixel(x,y)!=b_color&& getpixel(x,y)!=f_color)
 {
 putpixel(x,y,f_color);
  boundary_fill( x+1,  y,   f_color,  b_color);
  boundary_fill( x-1, y,    f_color,  b_color);
  boundary_fill( x,   y+1,  f_color,  b_color);
  boundary_fill( x,   y-1,  f_color,  b_color);
  boundary_fill( x+1, y+1,  f_color,  b_color);
  boundary_fill( x+1, y-1,  f_color,  b_color);
  boundary_fill( x-1, y+1,  f_color,  b_color);
  boundary_fill( x-1, y-1,  f_color,  b_color);
 }
 delay(3);
 }





// Define drawPlant, drawFish, and drawSeaCreature functions here
void drawPlant(int x,int y) {
    setcolor(GREEN);
    x=x+y;

}


void drawFish(struct Fish fish) {
    setcolor(YELLOW);
    // Fish body
    //ellipse(fish.x, fish.y, 0, 360, 20, 8);
    line(fish.x-35,fish.y,fish.x,fish.y+30);
    line(fish.x-35,fish.y,fish.x,fish.y-30);
    line(fish.x+35,fish.y,fish.x,fish.y-30);
    line(fish.x+35,fish.y,fish.x,fish.y+30);

    // Tail
    line(fish.x-35,fish.y,fish.x-50,fish.y+15);
    line(fish.x-35,fish.y,fish.x-50,fish.y-15);
    line(fish.x-50,fish.y+15,fish.x-50,fish.y-15);
    // tail[8] = {fish.x - 22, fish.y - 3, fish.x - 22, fish.y + 3, fish.x - 28, fish.y, fish.x - 22, fish.y - 3};
   // fillpoly(4, tail);

    // Eyes
       circle(fish.x+25,fish.y,2);
       fillellipse(fish.x+25,fish.y,0,0);


}

void drawBubble(int x,int y) {
    // Implement bubble with transparency and shimmering effect
    // For example:
    setcolor(LIGHTCYAN);
    //while(y<)
    circle(x, y, 5);
    // Implement animation or other effects for bubbles
}
void drawSeaCreature(struct SeaCreature creature) {

    setcolor(WHITE);
    //fish
    ellipse(creature.x,creature.y+200,0,360,55,35);
    arc(creature.x+28,creature.y+200,90,265,30);
    arc(creature.x+30,creature.y+200,90,260,30);
    line(creature.x-54,creature.y+200,creature.x-74,creature.y+220);
    line(creature.x-54,creature.y+200,creature.x-74,creature.y+180);
    line(creature.x-74,creature.y+220,creature.x-74,creature.y+180);
    circle(creature.x+40,creature.y+195,4);
    fillellipse(creature.x+40,creature.y+195,0,0);

   // fish2
    ellipse(creature.x-240,creature.y+220,290,70,90,50);
   // line(creature.x-280,creature.y+220,creature.x-200,creature.y+220);
    arc(creature.x-220,creature.y+200,300,60,28);
    arc(creature.x-220,creature.y+245,300,60,25);

   // mouth
    ellipse(creature.x-145,creature.y+220,137,228,30,40);
    circle(creature.x-160,creature.y+210,3);
    fillellipse(creature.x-160,creature.y+210,0,0);

   // tail
   line(creature.x-205,creature.y+225,creature.x-230,creature.y+200);
   line(creature.x-205,creature.y+225,creature.x-230,creature.y+250);
   line(creature.x-230,creature.y+250,creature.x-230,creature.y+200);


}
    void drawSeaCreature2(struct SeaCreature creature) {

   //Fish3
   arc(creature.x,creature.y+150,50,145,110);
   arc(creature.x-10,creature.y+10,225,320,110);

  // tail
  line(creature.x+70,creature.y+65,creature.x+110,creature.y+35);
  line(creature.x+74,creature.y+82,creature.x+114,creature.y+110);
  line(creature.x+90,creature.y+74,creature.x+114,creature.y+110);
  line(creature.x+90,creature.y+74,creature.x+110,creature.y+35);

  //mouth
  arc(creature.x-104,creature.y+114,0,48,85);
  circle(creature.x-65,creature.y+80,3);
  line(creature.x-88,creature.y+87,creature.x-75,creature.y+87);

  //fin
  arc(creature.x+35,creature.y+110,120,140,100);
  line(creature.x,creature.y+40,creature.x-16,creature.y+25);
 // fin2
  line(creature.x,creature.y+80,creature.x+14,creature.y+75);
  line(creature.x+14,creature.y+75,creature.x+13,creature.y+85);
  line(creature.x,creature.y+85,creature.x+13,creature.y+85);


  //fin3
  line(creature.x+75,creature.y+82,creature.x+50,creature.y+115);
  line(creature.x+50,creature.y+112,creature.x+45,creature.y+105);
}



void drawSeaFloor() {
    // Implement a detailed sea floor with textures and lighting
    // For example, you can add sand, rocks, and other underwater elements.

    //rock
    setcolor(BROWN);
     ellipse(0,470,0,360,18,15);
     ellipse(40,470,0,360,19,15);
     ellipse(100,470,0,360,39,12);
     ellipse(175,470,0,360,30,9);
     ellipse(225,470,0,360,18,10);
     ellipse(285,470,0,360,40,13);
     ellipse(350,470,0,360,20,15);
     ellipse(405,470,0,360,30,12);
     ellipse(450,470,0,360,10,15);
     ellipse(503,460,0,360,40,20);
     ellipse(580,470,0,360,40,12);
     ellipse(660,470,0,360,40,22);
 //   layer 2
     ellipse(20,441,0,360,30,14);
     ellipse(60,449,0,360,10,14);
     ellipse(100,438,0,360,30,20);
     ellipse(137,455,0,360,20,6);
     ellipse(150,440,0,360,19,7);
     ellipse(174,452,0,360,15,8);
     ellipse(225,440,0,360,40,20);
     ellipse(280,440,0,360,15,15);
     ellipse(320,440,0,360,25,23);
     ellipse(375,440,0,360,30,20);
     ellipse(435,440,0,360,30,15);
     ellipse(485,430,0,360,20,13);
     ellipse(568,430,0,360,40,30);
     ellipse(640,420,0,360,30,30);

    //sea grass
    setcolor(GREEN);
    line(300,300,320,280);
    line(300,300,318,280);
    line(300,300,315,280);
    line(300,300,312,280);
    line(300,300,310,280);
    line(300,300,308,280);
    line(300,300,305,280);
    line(300,300,302,280);
    line(300,300,300,280);
    line(300,300,300-2,280);
    line(300,300,300-5,280);
    line(300,300,300-8,280);
    line(300,300,300-10,280);
    line(300,300,300-12,280);
    line(300,300,300-15,280);
    line(300,300,300-18,280);
    line(300,300,300-20,280);

    line(300,300,300,430);

    //branch 2
    line(300,350,340,310);
    line(340,310,340,300);

    line(300+40,300,320+40,280);
    line(300+40,300,318+40,280);
    line(300+40,300,315+40,280);
    line(300+40,300,312+40,280);
    line(300+40,300,310+40,280);
    line(300+40,300,308+40,280);
    line(300+40,300,305+40,280);
    line(300+40,300,302+40,280);
    line(300+40,300,300+40,280);
    line(300+40,300,300-2+40,280);
    line(300+40,300,300-5+40,280);
    line(300+40,300,300-8+40,280);
    line(300+40,300,300-10+40,280);
    line(300+40,300,300-12+40,280);
    line(300+40,300,300-15+40,280);
    line(300+40,300,300-18+40,280);
    line(300+40,300,300-20+40,280);

   // branch 3

   line(300,400,270,370);
   line(270,370,270,360);

    line(300-30,300+60,320-30,280+50);
    line(300-30,300+60,318-30,280+50);
    line(300-30,300+60,315-30,280+50);
    line(300-30,300+60,312-30,280+50);
    line(300-30,300+60,310-30,280+50);
    line(300-30,300+60,308-30,280+50);
    line(300-30,300+60,305-30,280+50);
    line(300-30,300+60,302-30,280+50);
    line(300-30,300+60,300-30,280+50);
    line(300-30,300+60,300-2-30,280+50);
    line(300-30,300+60,300-5-30,280+50);
    line(300-30,300+60,300-8-30,280+50);
    line(300-30,300+60,300-10-30,280+50);
    line(300-30,300+60,300-12-30,280+50);
    line(300-30,300+60,300-15-30,280+50);
    line(300-30,300+60,300-18-30,280+50);
    line(300-30,300+60,300-20-30,280+50);


   // grass 2
     x=100,y=350;
    setcolor(GREEN);
    line(100,350,120,330);
    line(x,y,x-20,y-20);
    line(x,y,x-18,y-20);
    line(x,y,x-15,y-20);
    line(x,y,x-12,y-20);
    line(x,y,x-10,y-20);
    line(x,y,x-8,y-20);
    line(x,y,x-5,y-20);
    line(x,y,x-2,y-20);
    line(x,y,x,y-20);
    line(x,y,x+2,y-20);
    line(x,y,x+5,y-20);
    line(x,y,x+8,y-20);
    line(x,y,x+10,y-20);
    line(x,y,x+12,y-20);
    line(x,y,x+15,y-20);
    line(x,y,x+18,y-20);
    line(x,y,x+20,y-20);


    line(100,350,100,400);

    //branch 2
    line(100,350,100,420);
    line(x,y+40,x+20,y+20);
    x=x+20;
    y=y+20;
    line(x,y,x,y);
    line(x,y,x-20,y-20);
    line(x,y,x-18,y-20);
    line(x,y,x-15,y-20);
    line(x,y,x-12,y-20);
    line(x,y,x-10,y-20);
    line(x,y,x-8,y-20);
    line(x,y,x-5,y-20);
    line(x,y,x-2,y-20);
    line(x,y,x,y-20);
    line(x,y,x+2,y-20);
    line(x,y,x+5,y-20);
    line(x,y,x+8,y-20);
    line(x,y,x+10,y-20);
    line(x,y,x+12,y-20);
    line(x,y,x+15,y-20);
    line(x,y,x+18,y-20);
    line(x,y,x+20,y-20);

   // branch 3
   x=100;y=405;
   line(x,y,x-30,y-40);
   x=x-30;y=y-40;
    line(x,y,x-20,y-20);
    line(x,y,x-18,y-20);
    line(x,y,x-15,y-20);
    line(x,y,x-12,y-20);
    line(x,y,x-10,y-20);
    line(x,y,x-8,y-20);
    line(x,y,x-5,y-20);
    line(x,y,x-2,y-20);
    line(x,y,x,y-20);
    line(x,y,x+2,y-20);
    line(x,y,x+5,y-20);
    line(x,y,x+8,y-20);
    line(x,y,x+10,y-20);
    line(x,y,x+12,y-20);
    line(x,y,x+15,y-20);
    line(x,y,x+18,y-20);
    line(x,y,x+20,y-20);



   // grass 3

   line(560,400,560,350);
   x=560;
   y=350;
    line(x,y,x-20,y-20);
    line(x,y,x-18,y-20);
    line(x,y,x-15,y-20);
    line(x,y,x-12,y-20);
    line(x,y,x-10,y-20);
    line(x,y,x-8,y-20);
    line(x,y,x-5,y-20);
    line(x,y,x-2,y-20);
    line(x,y,x,y-20);
    line(x,y,x+2,y-20);
    line(x,y,x+5,y-20);
    line(x,y,x+8,y-20);
    line(x,y,x+10,y-20);
    line(x,y,x+12,y-20);
    line(x,y,x+15,y-20);
    line(x,y,x+18,y-20);
    line(x,y,x+20,y-20);

}

void drawLightEffects() {
    // Implement advanced light and shadow effects
    // This would require a more complex rendering system.
    // Consider using a modern graphics library for this.
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    setbkcolor(BLUE);

  //  struct Fish fishes[5];
    for ( i = 0; i < MAX_FISH; i++) {
	fishes[i].x = 50 + i * 100;
	fishes[i].y = 100;
	fishes[i].speed = 2;
	fishes[i].direction = 1;
	fishes[i].angle = 0;
	fishes[i].frame = 0;
    }

   // struct SeaCreature creatures[MAX_CREATURES];
    // Initialize sea creatures' properties
    // You should specify properties for various sea creatures here.
    for ( i = 0; i < MAX_CREATURES; i++) {
	// Example properties for sea creatures
	creatures[i].x = rand() % getmaxx();
	creatures[i].y = rand() % getmaxy();
	creatures[i].speed = 1;
	creatures[i].direction = (rand() % 2 == 0) ? 1 : -1; // Random direction
       creatures[i].angle = 0;
     creatures[i].color = (255, 0, 0); // Red, you can choose any color
    }

    for ( i = 0; i < MAX_CREATURES; i++) {
	// Example properties for sea creatures
	creatures2[i].x = rand() % getmaxx();
	creatures2[i].y = rand() % getmaxy();
	creatures2[i].speed = 1;
	creatures2[i].direction = (rand() % 2 == 0) ? 1 : -1; // Random direction
       creatures2[i].angle = 0;
     creatures2[i].color = (255, 0, 0); // Red, you can choose any color
    }


    // Initialize bubble positions

    while (!kbhit()) {
	cleardevice();

	for ( i = 0; i < MAX_FISH; i++) {
	    // Calculate vertical motion for fish animation
	    int vertical_motion = 5 * sin(fishes[i].angle * 3.14159265 / 180);
	    drawFish(fishes[i]);
	   fishes[i].x += fishes[i].direction * fishes[i].speed;
	    fishes[i].angle += 10;
	    fishes[i].frame = (fishes[i].frame + 1) % 2; // Two animation frames

	    if (fishes[i].x > getmaxx()) {
		fishes[i].x = 0;
		fishes[i].direction = 1;
	    } else if (fishes[i].x < 0) {
		fishes[i].x = getmaxx();
		fishes[i].direction = -1;
	    }
	}

       for ( i = 0; i < MAX_CREATURES; i++) {
	    // Implement sea creature animation
	    // You should add logic for animation of other sea creatures.
	    drawSeaCreature(creatures[i]);
	    creatures[i].x += creatures[i].direction * creatures[i].speed;
	    if (creatures[i].x > getmaxx() + 20 || creatures[i].x < -20) {
		creatures[i].x = (creatures[i].direction == 1) ? -20 : getmaxx() + 20;
	    }

	 for ( i = 0; i < MAX_CREATURES; i++) {
	    // Implement sea creature animation
	    // You should add logic for animation of other sea creatures.
	    drawSeaCreature2(creatures2[i]);
	    creatures2[i].x+= creatures2[i].direction * creatures2[i].speed;
	    if (creatures2[i].x > getmaxx() + 20 || creatures2[i].x < -20) {
		creatures2[i].x = (creatures2[i].direction == 1) ? -20 : getmaxx() + 20;
	    }
	}


	for ( i = 0; i < 1; i++) {
	    drawBubble(bubble_x[i], bubble_y[i]);
	    bubble_x[i]=rand()%getmaxx();
	    bubble_y[i] =rand() % getmaxx();
	    for(i=0;i<10;i++){
	    bubble_y[i]=bubble_y[i]+100;
	    drawBubble(bubble_x[i],bubble_y[i]);

	    if (bubble_y[i] < 0) {
		bubble_x[i] = rand() % getmaxx();
		bubble_y[i] = getmaxy();
	    }
	    }
	}

       //	drawPlant(plant_x, plant_y);



	      drawSeaFloor();

       //	drawLightEffects();

	// Implement user interaction (if desired)

	delay(60);
    }
}
    closegraph();
    return 0;
}