#include "shield.h"
#include <cmath>
#include <cstring>

Shield::Shield()
{
    this -> currentDirection = 4;
    this -> position.x = 300;
    this -> position.y = 300;
    this -> angle = -90;
}

void Shield::update()
{
    
}

void Shield::turn(const char* direction)
{
    if (strcmp(direction, "RIGHT") == 0)
    {
        this -> currentDirection = 0;
        this -> position.x = 375;
        this -> position.y = 200;
        this -> angle = 180;
    }
    else if (strcmp(direction, "UP") == 0)
    {
        this -> currentDirection = 1;
        this -> position.x = 325;
        this -> position.y = 150;
        this -> angle = 90;
    }
    else if (strcmp(direction, "LEFT") == 0)
    {
        this -> currentDirection = 2;
        this -> position.x = 250;
        this -> position.y = 200;
        this -> angle = 0;
    }
    else if (strcmp(direction, "DOWN") == 0)
    {
        this -> currentDirection = 3;
        this -> position.x = 325;
        this -> position.y = 275;
        this -> angle = -90;
    }
}