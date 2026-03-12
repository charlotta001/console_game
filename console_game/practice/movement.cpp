#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cctype>

int headX, headY; 
int WIDTH = 30, HEIGHT = 15;

bool gameLoop = false;
int tailX[100],tailY[100];
int tailLen = 5;


enum Direction{
   STOP,UP,DOWN,LEFT,RIGHT
};
Direction dir = STOP;



void setup();
void update();
void draw();
void  input();


int main(){
    // for(int i = 0; i < argc ; i++){
    //     std::cout << i << ": " << argv << "\n";
    // }

    setup();
    draw();
    while(!gameLoop){
        input();
        update();
        draw();

        Sleep(60);
    }
    
}

void setup(){

    headX = WIDTH / 2; // 30
    headY = HEIGHT / 2; // 15

    for(int i = 0; i < 5 ; i++){
        tailX[i] = (WIDTH / 2 );
        tailY[i] = (HEIGHT / 2) + (i+1);
    }
    dir = STOP;
    
}

void draw(){    
    system("cls");

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            //atas bawah
            if(i == 0 || i == HEIGHT - 1){
                std::cout << "*";
            // kanan kiri
            } else if(j == 0 || j == WIDTH - 1){
                std::cout << "*";
            }else if(i == headY && j == headX){
                std::cout << "K";
            
            } else {
    bool isTail = false;
    for(int k = 0; k < tailLen; k++){
        if(tailX[k] == j && tailY[k] == i){
            isTail = true;
            break;
        }
    }
    std::cout << (isTail ? "o" : " ");
}
        }
        std::cout << "\n";
    }
    
}

void input(){
    if(_kbhit()){
        switch(tolower(_getch())){
            case 'w': dir = UP; break;
            case 'a': dir = LEFT; break;
            case 's': dir = DOWN; break;
            case 'd': dir = RIGHT; break;
        }
    }
    
}

void update(){

    if(dir != STOP){
    for(int i = tailLen; i > 0; i--){
    tailX[i] = tailX[i -1];
    tailY[i] = tailY[i -1];
    }

    if( tailLen > 0){
        tailX[0] = headX;
        tailY[0] = headY;
    }
}

    if(dir == UP) headY--;
    if(dir == DOWN) headY++;
    if(dir == LEFT) headX--;
    if(dir == RIGHT) headX++;

    if(headX == 0){
        headX = WIDTH - 2;
    } else if(headX == WIDTH  -1){
        headX = 1 ;
    } else if(headY == 0){
        headY = HEIGHT - 2;
    } else if(headY == HEIGHT - 1){
        headY  = 1;
    }
}