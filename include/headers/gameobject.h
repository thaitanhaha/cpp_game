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
        float texture_offset_x, texture_offset_y;

        GameObject();
        void update();
        bool CheckCollision(GameObject);
};

#endif