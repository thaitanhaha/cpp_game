#ifndef BALLOON_H
#define BALLOON_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "gameobject.h"

class Balloon : public GameObject
{
    private:

    public:
        Balloon();
        Balloon(float, float);
};

#endif