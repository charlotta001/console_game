#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cctype>

int headX[2], headY[2]; 
int WIDTH = 30, HEIGHT = 15;

bool gameLoop = false;
int tailX[100],tailY[100];
int tailLen = 5;

int foodX, foodY;
int newdirX = 0, newdirY  =0;
int curdirX = 0, curdirY  =0;
//srand(times(0));



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

    headX[0] = WIDTH / 2; // 30
    headY[0] = HEIGHT / 2; // 15

    for(int i = 0; i < 5 ; i++){
        tailX[i] = (WIDTH / 2 );
        tailY[i] = (HEIGHT / 2) + (i+1);
    }
    dir = STOP;
    foodX =rand() % (WIDTH - 2 ) + 1;
    foodY= rand() % (HEIGHT - 2 ) + 1;

    curdirX = 0;
    curdirY = 0;
    
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
            }else if(i == headY[0] && j == headX[0]){
                std::cout << "K";
            
            } else if(i == foodY && j == foodX){
                std::cout << "M";
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
            case 'w': 
            {
                dir = UP; 
                newdirX = 0;
                newdirY = -1;
                break;
            }
            case 'a': 
            {
                dir = LEFT; 
                newdirX = -1;
                newdirY = 0;
                break;
            }    
            case 's': 
            {
                dir = DOWN; 
                newdirX  = 0;
                newdirY = 1;
                break;
            }
            case 'd': 
            {
                dir = RIGHT; 
                newdirX = 1;
                newdirY = 0;
                break;
            }
        
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
        tailX[0] = headX[0];
        tailY[0] = headY[0];
    }

    bool isReverse = (newdirX  == -curdirX && newdirY  == -curdirY);
    bool isStopped = (curdirX == 0 && curdirY  == 0);

    if(!isReverse || isStopped){
        curdirX = newdirX;
        curdirY = newdirY;
    }

    headX[0] += curdirX;
    headY[0] += curdirY;
}


    


    if(headX[0] == 0){
        headX[0] = WIDTH - 2;
    } else if(headX[0] == WIDTH  -1){
        headX[0] = 1 ;
    } else if(headY[0] == 0){
        headY[0] = HEIGHT - 2;
    } else if(headY[0] == HEIGHT - 1){
        headY[0]  = 1;
    }

    if(headX[0] ==  foodX && headY[0] == foodY){
        tailLen++;
        foodX = rand() % (WIDTH -2) + 1;
        foodY = rand() % (HEIGHT -2) + 1;
    }

}