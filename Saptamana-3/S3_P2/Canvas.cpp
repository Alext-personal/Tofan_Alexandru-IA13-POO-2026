#include "Canvas.h"
#include <stdio.h>
Canvas::Canvas(int width, int height)
{
    this -> width = width;
    this -> height = height;
    this -> canvas = new char*[width];
    for (int i = 0; i < width; i++)
        this -> canvas[i] = new char[height];
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            this -> canvas[i][j] = ' ';
}
void Canvas::DrawCirclePoints(int x, int y, int x1,int y1,char ch)
{
    SetPoint(x+x1, y+y1, ch);
    SetPoint(x-x1, y+y1, ch);
    SetPoint(x+x1, y-y1, ch);
    SetPoint(x-x1, y-y1, ch);
    SetPoint(x+y1, y+x1, ch);
    SetPoint(x-y1, y+x1, ch);
    SetPoint(x+y1, y-x1, ch);
    SetPoint(x-y1, y-x1, ch);
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int x1 = 0, y1 = ray;
    int d = 3 - 2 * ray;
    DrawCirclePoints(x, y, x1, y1,ch);
    while (y1 >= x1){
        if (d > 0) {
            y1--; 
            d = d + 4 * (x1 - y1) + 10;
        }
        else
            d = d + 4 * x1 + 6;
        x1++;
        DrawCirclePoints(x, y, x1, y1,ch);
    }
}
bool IsInsideCircle(int x, int y, int ray,int x1,int y1) // x , y sunt coord centrului cercului, x1 ,y1 sunt coordonatele punctului pt care se face verificarea
{
    return (x1-x)*(x1-x) + (y1-y)*(y1-y) <= (ray*ray);
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    DrawCircle(x,y,ray,ch);
    for (int i = x - ray; i <= x + ray; i++)
        for (int j = y - ray; j <= y + ray; j++)
            if (IsInsideCircle(x,y,ray,i,j))
                SetPoint(i,j,ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left,top,right,top,ch);
    DrawLine(left,bottom,right,bottom,ch);
    DrawLine(left,top,left,bottom,ch);
    DrawLine(right,top,right,bottom,ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        DrawLine(left,i,right,i,ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
    this -> canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    if (x1 > x2 || y1 > y2)
    {
        printf("ERROR WITH BRESENHAM'S LINE DRAWING ALGORITHM, X1 > X2 OR Y1 > Y2");
        return;
    }
    if (x1 == x2)
    {
        for (int y = y1; y <= y2; y++)
            SetPoint(x1,y,ch);
        return;
    }
    if (y1 == y2)
    {
        for (int x = x1; x <= x2; x++)
            SetPoint(x,y1,ch);
        return;
    }
    int m = 2 * (y2 - y1);
    int slope_error = m - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++) {
        SetPoint(x,y,ch);
        slope_error += m;
        if (slope_error >= 0) {
            y++;
            slope_error -= 2 * (x2 - x1);
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < this -> width; i++)
    {
        for (int j = 0; j < this -> height; j++)
            printf("%c ",this -> canvas[i][j]);
        printf("\n");
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < this -> width; i++)
        for (int j = 0; j < this -> height; j++)
            SetPoint(i,j,' ');
}
