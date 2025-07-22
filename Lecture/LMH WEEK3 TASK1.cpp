#include <graphics.h>
#include <conio.h>
int main (){
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");
rectangle(100,400,200,50);


//setviewport(100,200,400,400,1);
/*int polygon[]=
{300,200,350,250,350,300,300,350,250,300,250,250,300,200};
drawpoly(7,polygon);*/

getch();
closegraph();
return 0;
}
