#ifndef LASER_H
#define LASER_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "gameobject.h"

class Laser : public GameObject
{
    private:
        float speed;
        float angle_x; 
        float angle_y;
    public: 
        float angle;

        Laser();
        Laser(float, float, float);
        void RandomStartingPoint(float, float);

        ~Laser();
        void ResetLaser(float, float, float);
        void update();
};

#endif