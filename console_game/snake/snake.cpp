#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <cctype>

// compile : g++ snake.cpp -o snake.exe
// setup()
// draw()
// input()
// update()
// main()


// snake
int headX, headY;
int tailX[100], tailY[100];
int tailLen = 0;

// food
int foodX, foodY;
int score = 0;

// game loop
bool gameLoop = false;

// direction
enum Direction{STOP, UP, DOWN, LEFT, RIGHT };
Direction dir = STOP;

const int WIDTH = 40;
const int HEIGHT = 20;

char wallInside = ' ';


int a = 1000;

void setup(){
    gameLoop = false;
    dir = STOP;
    score = 0;
    tailLen = 0;

    // head spawn in the middle of domain
    headX = WIDTH / 2;
    headY = HEIGHT / 2;

    // random food
    // a mod n = x
    // x = 0 <= n-1
    // so the food will be exist inside domain 
    srand(time(0));
    foodX = rand() % (WIDTH - 2) + 1;
    foodY = rand() % (HEIGHT - 2) + 1;
}

void draw(){
    system("cls");
    for(int i = 0; i < HEIGHT; i++){
        for(int j= 0; j <  WIDTH; j++){
            if(i == 0 || i == HEIGHT - 1){
                std::cout << "*";
            } else if(j == 0 || j == WIDTH - 1){
                std::cout << "*";
            } else if(i == headY && j == headX){
                std::cout << '@';
            } else if(i == foodY && j == foodX){
                std::cout << 'M';
            } else {
                bool isTail = false;
                for(int k =0; k < tailLen; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        isTail = true;
                        break;
                }
             }
            std::cout << ((isTail) ? 'o' : ' ');
            }
        }
    std::cout << std::endl;
   } 


}

void input() {
    if(_kbhit()){
        switch(std::tolower(_getch())){
            case 'w': dir = UP; break;
            case 'a': dir = LEFT; break;
            case 's': dir = DOWN; break;
            case 'd': dir = RIGHT; break;
        }
    }
} 

void update(){ 
    // update ekor mengikuti kepala
    for(int i = tailLen - 1; i > 0; i--){
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    if(tailLen > 0){
        tailX[0] = headX;
        tailY[0] = headY;
    }

    // gerakan kepala
    if(dir == UP) headY--;
    if(dir == DOWN) headY++;
    if(dir == RIGHT) headX++;
    if(dir == LEFT) headX--;

    // cek tabrakan ekor
    for(int i = 0; i < tailLen; i++){
        if(headX == tailX[i] && headY == tailY[i]){
            gameLoop = true;
        }
    }

    // cek tabrakan tembok
    if(headX <= 0 || headX >= WIDTH || headY <= 0 || headY >= HEIGHT){
        gameLoop = true;
    }

    // panjang makan food
    if(headX == foodX && headY == foodY){
        tailLen +=100;
        foodX = rand() % (WIDTH - 2) + 1;
        foodY = rand() % (HEIGHT - 2) + 1;

    }



     
}

int main() {

    setup();

    while(!gameLoop){
        input();
        update();
        draw();
        Sleep(60);
    }
}