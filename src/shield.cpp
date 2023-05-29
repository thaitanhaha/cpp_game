#include "shield.h"
#include <cmath>
#include <cstring>

Shield::Shield()
{
    this -> currentDirection = 4;
    this -> x = 300;
    this -> y = 300;
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
        this -> x = 375;
        this -> y = 200;
        this -> angle = 180;
    }
    else if (strcmp(direction, "UP") == 0)
    {
        this -> currentDirection = 1;
        this -> x = 325;
        this -> y = 150;
        this -> angle = 90;
    }
    else if (strcmp(direction, "LEFT") == 0)
    {
        this -> currentDirection = 2;
        this -> x = 250;
        this -> y = 200;
        this -> angle = 0;
    }
    else if (strcmp(direction, "DOWN") == 0)
    {
        this -> currentDirection = 3;
        this -> x = 325;
        this -> y = 275;
        this -> angle = -90;
    }
    // std::cout << this->x << " " << this->y;
}