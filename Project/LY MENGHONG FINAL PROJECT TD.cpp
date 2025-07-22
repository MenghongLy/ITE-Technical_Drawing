#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


int groundY = 350;  
int dinoX = 50, dinoY = 345;  
bool isJumping = false;
int jumpHeight = 200, jumpSpeed = 15, dinoVelocityY = 0;

int cactusX = 640, cactusY = 345; 
int cactusSpeed = 30;
int score;
bool isGameOver = false;

//====================================drawground=====================================================
void drawGround() {
    setcolor(LIGHTGREEN);
    rectangle(0, 360, getmaxx(), 380);
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    floodfill(1, 361, LIGHTGREEN);

    setcolor(BROWN);
    rectangle(0, 380, getmaxx(), getmaxy());
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(1, 381, BROWN);
}
//==============================drawsky==========================================================
void drawcloud(int x, int y) {
    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    fillellipse(30, 10, 40, 40);
    setcolor(WHITE);
    setfillstyle(1, WHITE);

    fillellipse(x, y, 20, 20);        
    fillellipse(x + 20, y, 20, 20);   
    fillellipse(x + 40, y, 10, 10);  
    fillellipse(x - 20, y, 10, 10);   
}
void cloud() {
    for (int i = 0; i < 7; ++i) {
        int x = 100 + (i * 100);  
        int y = 40 + (rand() % 50);
        drawcloud(x, y);
    }
}
//=============================================drawDino==============================================

void drawDino(int x, int y) {
	
    // Dino body
    setcolor(LIGHTGRAY);
    rectangle(x, y - 30, x + 20, y + 5);  
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x + 1, y - 29, LIGHTGRAY);

    // Dino head
    rectangle(x - 1, y - 40, x + 30, y - 30);  
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x + 1, y - 39, LIGHTGRAY);

    // Eye 
    setcolor(BLACK);
    circle(x + 25, y - 40, 2);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 25, y - 40, BLACK);

    // Legs
    setcolor(LIGHTGRAY);
    rectangle(x + 3, y + 5, x + 8, y + 15);  // Left leg
    rectangle(x + 12, y + 5, x + 17, y + 15);  // Right leg
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x + 4, y + 6, LIGHTGRAY);
    floodfill(x + 13, y + 6, LIGHTGRAY);

    // Tail 
    rectangle(x - 10, y - 10, x, y);  
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(x - 5, y - 5, LIGHTGRAY);
}

//====================================cactus==========================================================

void drawCactus(int x, int y) {
	setcolor(GREEN);
    rectangle(x, y - 30, x + 20, y + 15); 
	setfillstyle(1,GREEN);
	floodfill(x + 1 , y - 29 , GREEN); 
}
//==============================================reset-game==================================================
void resetGame() {
    dinoY = 340;
    cactusX = 640;
    score = 0;
    isGameOver = false;
}

bool detectCollision() {
    if (dinoX + 30 >= cactusX && dinoX <= cactusX + 20 &&
        dinoY >= cactusY - 30) {
        return true;
    }
    return false;
}
//=======================================display-score======================================================
void displayScore() {
    setcolor(BLACK);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);
    char scoreStr[10];
    sprintf(scoreStr, "Score: %d", score);
    outtextxy(300, 10, scoreStr);
}
//================================================gameloop=================================================

void gameloop(){
	  srand(time(0)); 
	  

    while (true) {
        cleardevice(); 
		drawGround();
        cloud(); 
        displayScore();
        
          // Dino jump 
        if (isJumping) {
            dinoY -= dinoVelocityY;
            dinoVelocityY -=3;  

            if (dinoY >= groundY - 5) {
                dinoY = groundY - 5;
                isJumping = false;
            }
        }

        
        drawDino(dinoX, dinoY);

        // Move cactus and reset if off-screen
        cactusX -= cactusSpeed;
        if (cactusX < 0) {
            cactusX = getmaxx();
            cactusY = groundY - 5;
            score++;
        }

        // Draw Cactus
        drawCactus(cactusX, cactusY);

        if (detectCollision()) {
        	setcolor(BLACK);
        	settextstyle(3,HORIZ_DIR , 5);
            outtextxy(getmaxx() / 2 - 50, getmaxy() / 2, "Game Over!");
            isGameOver = true;
            getch();  
            resetGame();
        }

        if (kbhit()) {
            char ch = getch();
            if (ch == ' ' && !isJumping) {
                isJumping = true;
                dinoVelocityY = jumpSpeed;
            }
        }

        delay(50);  
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "TDM-GCC-32");
    setbkcolor(LIGHTBLUE);
    cleardevice();
	gameloop();
    
	 closegraph();  
    return 0;
}

