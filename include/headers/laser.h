#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
// #include "game.h"

class Laser
{
    private:
        float speed;
        float angle_x; 
        float angle_y;
    public: 
        float x;
        float y;
        float angle;
        SDL_Texture* laser_texture;

        Laser();
        Laser(float, float, float);
        void RandomStartingPoint(float, float);

        ~Laser();
        void ResetLaser(float, float, float);
        void update();
};