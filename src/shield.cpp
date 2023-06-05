#include "shield.h"
#include <cmath>
#include <cstring>

Shield::Shield()
{
    this -> currentDirection = 4;
    this -> position.x = 0;
    this -> position.y = 0;
    this -> angle = 0;

    this -> texture_offset_x = 0;
    this -> texture_offset_y = 0;
}

Shield::Shield(int currentDirection, float x, float y, int angle)
{
    this -> currentDirection = currentDirection;
    this -> position.x = x;
    this -> position.y = y;
    this -> angle = angle;

    this -> texture_offset_x = 648/36;
    this -> texture_offset_y = 3;
}

void Shield::turn(const char* direction)
{
    if (strcmp(direction, "RIGHT") == 0)
    {
        this -> currentDirection = 0;
        this -> position.x = 340;
        this -> position.y = 225;
        this -> angle = -90;

        this -> texture_offset_x = 648/36;
        this -> texture_offset_y = 10;
    }
    else if (strcmp(direction, "UP") == 0)
    {
        this -> currentDirection = 1;
        this -> position.x = 285;
        this -> position.y = 175;
        this -> angle = 0;

        this -> texture_offset_x = 648/36;
        this -> texture_offset_y = 3;
    }
    else if (strcmp(direction, "LEFT") == 0)
    {
        this -> currentDirection = 2;
        this -> position.x = 230;
        this -> position.y = 225;
        this -> angle = 90;

        this -> texture_offset_x = 648/36;
        this -> texture_offset_y = 3;
    }
    else if (strcmp(direction, "DOWN") == 0)
    {
        this -> currentDirection = 3;
        this -> position.x = 285;
        this -> position.y = 275;
        this -> angle = 0;

        this -> texture_offset_x = 648/36;
        this -> texture_offset_y = 3;
    }
}