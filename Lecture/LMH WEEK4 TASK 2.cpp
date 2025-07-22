#include <graphics.h>
#include <conio.h>
#include <unistd.h>
int main ()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\ TDM-GCC-32");
for(int i=0;i<11;i++){
cleardevice();
settextstyle( i , HORIZ_DIR,2);
settextjustify(LEFT_TEXT,CENTER_TEXT);
outtextxy(100,300,"C Programming text with outtextxy");
sleep(2);
}
getch();
closegraph();
return 0;
}
