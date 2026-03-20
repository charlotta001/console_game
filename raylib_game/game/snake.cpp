#include <iostream>
#include "raylib.h"
#include <math.h>
#include "rlgl.h"       //3d required
#include "raymath.h"    // 3d required
#include <math.h>


// ==============================================================
                    /* global variable*/
//===============================================================


struct Snake{
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;    
};


static int score = 0;
static int tailLen = 0;
static const int widthScreen = 800;
static const int heightScreen = 600;

static bool pause = false;
static bool gameOver = false;

static const int colSize =  60;
static const int rowSize =  80;
static const int col = 10;
static const int row = 10;


static int xPos_right = 0;
static int xPos_left = 10;
static int yPos_state = 1;
static int loop_state = 0;


Camera2D camera = { 0 };
Rectangle rectangle = {400,300,80,60};


//Rectangle rectangle1 = {0,120,80,60};


// ==============================================================
                    /* function prototype */
//===============================================================
static void draw();
static void input();
static void update();
static void setup();
static void drawGrid();
static Color randomColor();
static Rectangle makeRectangle(int x, int y);
static void drawPatternRectangle(Rectangle rec, Color color);

// ==============================================================
                    /* entry point run the proram */
//===============================================================

int main(){
    setup();
    

    return 0;
}


static void setup(){
    InitWindow(widthScreen, heightScreen, "snake window raylib");
    SetTargetFPS(1000);


    camera.offset = Vector2{widthScreen/2.0f, heightScreen/2.0f};
    //camera.offset = Vector2{0.0f,0.0f};
    camera.target = Vector2{rectangle.x, rectangle.y };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    float timerColor = 0.0f;
    float intervalColor = 0.7f;

    float timerRectangle = 0.0f;
    float intervalRectangle = 0.1f;

    bool isRight = false;
    bool isLeft = false;


    Color recColora =  randomColor();
    Color recColorb =  randomColor();

    while(!WindowShouldClose()){
    
    
        camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove()*0.1f));
        

        //camera.zoom += GetMouseWheelMove() * 0.1f;
        
        BeginDrawing();
            
        
        BeginMode2D(camera);
            float dt = GetFrameTime();
            timerColor += dt;
            timerRectangle += dt;
            
            std::cout << "xPos_right :  " << xPos_right 
                      << "xPos_left :  "  << xPos_left 
                      << "|| timer Rectangle: " << timerRectangle 
                      << " ypos_state: " << yPos_state 
                      << std::endl;

             // get random color
            if(timerColor >= intervalColor){
                timerColor = 0.0f;
                recColora =  randomColor();
                recColorb =  randomColor();
            }


            if(isRight)
            {
                xPos_right = 1;
                isRight = false;
            } 

            if(isLeft){
                xPos_left = 10;
                isLeft = false;
            }
            
           
            if(timerRectangle >= intervalRectangle){
                
                timerRectangle = 0.0f;
                
                // moving rectangle 
                if(yPos_state % 2 != 0){
                    xPos_right++;
                    if(xPos_right > 10){
                        isRight = true;
                        yPos_state++;
                    }
                } else {
                    xPos_left--;
                    if(xPos_left < 1){
                        isLeft = true;
                        yPos_state++;
                    }
                }
                
              if(yPos_state > 10){
                yPos_state = 1;
              }
                
              
        
            } 

        
            if(yPos_state % 2 != 0 && xPos_right >= 1 && xPos_right <= 10){
                drawPatternRectangle(makeRectangle(xPos_right,yPos_state), recColora);
            } else if(xPos_left <= 10 && xPos_left >= 1) {
                drawPatternRectangle(makeRectangle(xPos_left,yPos_state), recColora);
            }

    
            DrawText(TextFormat("width: %i \nheigth: %i",GetScreenWidth(),GetScreenHeight()),20,30,30, BLUE);
            DrawText(TextFormat("getframetime: %f",dt),20,100,30, BLUE);
            DrawText(TextFormat("xPos_right: %d\n xPos_left: %d", xPos_right, xPos_left),20,130,20,RED);
            DrawFPS(10, 10);
            drawGrid();
            ClearBackground(WHITE);

           
        EndMode2D();
        EndDrawing();

    }
    CloseWindow();
    
}

// ==============================================================
                    /*  function    */
//===============================================================


// draw grid based width and height window
static void drawGrid(){

    // vertical lime
    for(int j=0; j <= col; j++){
        if(j == 5){
        DrawLine(j*rowSize, 0 ,j*rowSize , heightScreen, RED);
        continue;
        }
        DrawLine(j*rowSize, 0 ,j*rowSize , heightScreen, BLACK);
    }

    // horizontal line 
    for(int i = 0;  i <= row; i++){
         if(i == 5){
        DrawLine(0, i*colSize, widthScreen, i * colSize, RED);
        continue;
        }
        DrawLine(0, i*colSize, widthScreen, i * colSize, BLACK);
    }

}

static Color randomColor(){
    return Color{
        (unsigned char)GetRandomValue(0,255),
        (unsigned char)GetRandomValue(0,255),
        (unsigned char)GetRandomValue(0,255),
        255
    };
}


// make rectangle
static Rectangle makeRectangle(int x, int y){

    int x_awal = x - 1;
    int y_awal = y - 1;
    return Rectangle{
        (float)((x_awal)*(80)),
        (float)((y_awal)*(60)),
        80,
        60
    };
}

static void drawPatternRectangle(Rectangle rec, Color color){
    DrawRectangleRec(rec, color);
}

