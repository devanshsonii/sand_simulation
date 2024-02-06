#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;

bool compareColors(const Color& color1, const Color& color2)
{
    return color1.r == color2.r && color1.g == color2.g && color1.b == color2.b && color1.a == color2.a;
}

int main(){
    const int screenWidth = 725;
    const int screenHeight = 725;
    InitWindow(screenWidth, screenHeight, "Test");
    SetTargetFPS(60);
    vector<vector<Rectangle>> shape;
    vector<vector<Color>> colors;
    for(int i = 0; i < 90; i++){
        vector<Rectangle> temp;
        vector<Color> tempColor;
        for(int j = 0; j < 90; j++){
            Rectangle r1;
            r1.x = i*8;
            r1.y = j*8;
            r1.height = 6;
            r1.width = 6;
            temp.push_back(r1);
            tempColor.push_back(BLACK);
        }
        colors.push_back(tempColor);
        shape.push_back(temp);
    }
    while(!WindowShouldClose()){
        BeginDrawing();
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            Vector2 mousePos = GetMousePosition();
            for(int i = 0; i < shape.size(); i++){
                for(int j = 0; j < shape[i].size(); j++){
                    if(CheckCollisionPointRec(mousePos, shape[i][j])){
                        colors[i][j] = WHITE;
                        for(int k = j + 1; k < shape[i].size(); k++){
                            if(compareColors(colors[i][k], BLACK)){
                                colors[i][k] = WHITE;
                                colors[i][k - 1] = BLACK;
                            }
                        }
                    }
                }
            }
        }
        ClearBackground(BLACK);
        for(int i = 0; i < shape.size(); i++){
            for(int j = 0; j < shape[i].size(); j++){
                DrawRectangle(shape[i][j].x, shape[i][j].y, shape[i][j].width, shape[i][j].height, colors[i][j]);
            }
        }
        EndDrawing();
    }
    CloseWindow();
}
