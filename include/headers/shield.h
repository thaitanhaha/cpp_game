#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "gameobject.h"

class Shield : public GameObject
{
    private:

    public:
        int currentDirection; // 0 right 1 up 2 left 3 down
        int angle;

        Shield();
        Shield(float, float, float);

        void update();
        void turn(const char*);
};

#endif