#include <graphics.h>
#include <conio.h>
#include <math.h>

void Circle_small(int x, int y) {
    setcolor(GREEN);
    setfillstyle(1, GREEN);
    circle(x, y, 40);
    floodfill(x, y, GREEN);
}

void Circle_big() {
    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    circle(400, 300, 100);
    floodfill(400, 300, YELLOW);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TDM-GCC-32");
    setbkcolor(WHITE);
    cleardevice();

    int bigCircleX = 400, bigCircleY = 300, radius = 150;
    float angle = 0.0;
    int rounds = 0;

    while (rounds < 3) {
        cleardevice();
        Circle_big();

        int smallCircleX = bigCircleX + radius * cos(angle);
        int smallCircleY = bigCircleY + radius * sin(angle);

        Circle_small(smallCircleX, smallCircleY);

        angle += 0.05;

        if (angle >= 2 * M_PI) {
            angle = 0;
            rounds++;
        }

        delay(10); 
    }

    getch();
    closegraph();
    return 0;
}

