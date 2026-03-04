#include "Canvas.h"

#include <cstdarg>
#include <cstdio>

Canvas::Canvas(int lines, int columns)
{
    this -> lines = lines;
    this -> columns = columns;
    this -> canvas = new char*[lines];
    for (int i = 0; i < lines; i++)
        this -> canvas[i] = new char[columns];
    clear();
}

void Canvas::set_pixel(int x, int y, char value)
{
    this -> canvas[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
    va_list arg;
    va_start(arg, count);
    for (int i = 0; i < count; i++)
    {
        int x = va_arg(arg, int);
        int y = va_arg(arg, int);
        char value = va_arg(arg, char);
        set_pixel(x,y,value);
    }
    va_end(arg);
}

void Canvas::clear()
{
    for (int i = 0; i < this -> lines; i++)
        for (int j = 0; j < this -> columns; j++)
            set_pixel(i,j,' ');
}

void Canvas::print() const
{
    for (int i = 0; i < this -> lines; i++)
    {
        for (int j = 0; j < this -> columns; j++)
            printf("%c ", this -> canvas[i][j]);
        printf("\n");
    }
}
