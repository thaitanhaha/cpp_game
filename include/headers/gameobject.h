#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "position.h"

class GameObject
{
    public: 
        Position position;
        SDL_Texture* texture;

        GameObject();
};

#endif