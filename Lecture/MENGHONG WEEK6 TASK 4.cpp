#include <graphics.h>
#include <conio.h>
//======================flower=============================
 void flower(){
 	int x=250,y=200;
    setcolor(GREEN);
    line(250, 200, 250, 350);
    setcolor(YELLOW);
   	setfillstyle(SOLID_FILL, YELLOW);
    circle(230, 180, 20); 
    floodfill(230,180,YELLOW);
    
    circle(270, 180, 20);
	 floodfill(270,180,YELLOW); 
	 
    circle(230, 220, 20); 
     floodfill(230,220,YELLOW);
     
    circle(270,220, 20);
     floodfill(270,220,YELLOW);
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(250, 200, 20, 20);
    }
//==========================tree===========================
void tree(){
	int log[]=
	{430,200,430,300,470,300,470,200,430,200};
	setcolor(BROWN); 
	drawpoly(4,log); 
    setfillstyle(SOLID_FILL, BROWN);
    fillpoly(4,log);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(450, 150 , 60, 60);  
    fillellipse(400, 150, 40, 40);  
    fillellipse(500, 150, 40, 40);  
    
}
//===========================SUN================================
void sun(){
	setcolor(ORANGE);
	circle(100,100,30);
	setfillstyle(SOLID_FILL, ORANGE);
    floodfill(100,100,ORANGE);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(LIGHTBLUE);
    cleardevice();

   flower();
   tree();
   sun();
    getch();
    closegraph();
    return 0;
}

