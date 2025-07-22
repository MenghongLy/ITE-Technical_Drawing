#include <graphics.h>
#include <conio.h>
int main ()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");
int points[]{100,180,300,180,200,450,100,180};
drawpoly(4,points);
int point[]{100,350,200,100,300,350,100,350};
drawpoly(4,point);

getch();
closegraph();
return 0;
}
