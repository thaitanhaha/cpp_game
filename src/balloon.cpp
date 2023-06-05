#include "balloon.h"

Balloon::Balloon()
{
    this -> position.x = 0;
    this -> position.y = 0;
}

Balloon::Balloon(float x, float y)
{
    this -> position.x = x;
    this -> position.y = y;

    this -> texture_offset_x = 415/12;
    this -> texture_offset_y = 465/12;
}