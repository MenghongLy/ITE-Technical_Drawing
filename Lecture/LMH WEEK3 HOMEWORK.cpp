#include <graphics.h>
#include <conio.h>
int main ()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");

int 
for(int i=0 ;i<200;i++){
	cleardevice();
	circle(100+i ,300,20);
delay(50);

}



getch();
closegraph();
return 0;
}
