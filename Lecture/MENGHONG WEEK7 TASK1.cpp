#include <graphics.h>
#include <conio.h>
int main (){
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");

int midx = getmaxx()/2;
int midy = getmaxy()/2;
setviewport(midx - 100, midy -100 , midx + 100, midy + 100, 1);
int polygon[]=
{100,0,
150,50,
150,100,
100,150,
50,100,
50,50,
100,0};
drawpoly(7,polygon);
setfillstyle(XHATCH_FILL, RED);
fillpoly(7,polygon);


getch();
closegraph();
return 0;
}



