#include<graphics.h>
#include<conio.h>
#include<unistd.h>
int main(){
  int gd = DETECT, gm;
  initgraph(&gd,&gm,"C:\\TDM-GCC-32");
  settextstyle(SIMPLEX_FONT,VERT_DIR,2);
  settextjustify(LEFT_TEXT,CENTER_TEXT);
  outtextxy(100,100,"C Programming text without outtextxy");
  getch();
  closegraph();
  return 0;  
}
