#include <graphics.h>
#include <conio.h>
#include <dos.h>  

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    
    while (!kbhit()){
    	if (ismouseclick(WM_LBUTTONDOWN)){
    		int x,y;
    		getmouseclick(WM_LBUTTONDOWN,x,y);
    		circle(x,y,10);
    		cleardevice();
		}
	}
    getch();
    closegraph(); 
    return 0;
}

