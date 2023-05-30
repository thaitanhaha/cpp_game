#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class Position 
{
    public:
        float x;
        float y;
        Position();
        Position(float, float);
};

#endif