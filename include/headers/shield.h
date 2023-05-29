#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
// #include "game.h"

class Shield
{
    private:
        int currentDirection; // 0 right 1 up 2 left 3 down
    public:
        float x, y;
        int angle;
        SDL_Texture* shield_texture;

        Shield();
        Shield(float, float, float);

        void update();
        void turn(const char*);
};