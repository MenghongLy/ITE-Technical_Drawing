#include <graphics.h>
#include <conio.h>
int main ()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");
int points[] = {200,200,250,100,380,100,450,200,450,450,200,450,200,200,};
drawpoly(7,points);
getch();
closegraph();
return 0;
}
