#include <SDL.h>
#include <iostream>
#include <random>
#include "laser.h"
#include <vector>
using namespace std;

const int screenWidth = 640;
const int screenHeight = 512;

// vector <float> randomLaserStartPoint(mt19937 engine, 
//     uniform_int_distribution<int> edge, 
//     uniform_real_distribution<float> distribution_x, 
//     uniform_real_distribution<float> distribution_y)
// {
//     int edgeIndex = edge(engine);
//     float x, y;
//     switch (edgeIndex)
//     {
//         case 0:
//             x = distribution_x(engine);
//             y = 0.0;
//             break;
//         case 1:
//             x = 10.0;
//             y = distribution_y(engine);
//             break;
//         case 2:
//             x = distribution_x(engine);
//             y = 10.0;
//             break;
//         case 3:
//             x = 0.0;
//             y = distribution_y(engine);
//             break;
//     }
//     return {x,y};
// }

int main(int argc, char *argv[])
{
    GameManager game;
    
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> edge(0, 3);
    uniform_real_distribution<float> distribution_x(0.0f, (float) screenWidth);
    uniform_real_distribution<float> distribution_y(0.0f, (float) screenHeight);

    game.init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    SDL_Texture* background = game.loadTexture("sprite/background.png");
    SDL_Texture* balloon = game.loadTexture("sprite/balloon.png");
    SDL_Texture* shield = game.loadTexture("sprite/shield.png");

    int edgeIndex = edge(engine);
    float x, y;
    switch (edgeIndex)
    {
        case 0:
            x = distribution_x(engine);
            y = 0.0;
            break;
        case 1:
            x = screenWidth;
            y = distribution_y(engine);
            break;
        case 2:
            x = distribution_x(engine);
            y = screenHeight;
            break;
        case 3:
            x = 0.0;
            y = distribution_y(engine);
            break;
    }
    Laser ls(x, y, 0.02);
    ls.laser_texture = game.loadTexture("sprite/laser.png");

    while (game.gameState != GAMESTATE::QUIT)
    {
        SDL_Event windowEvent;
        SDL_PollEvent(&windowEvent);
        switch (windowEvent.type)
        {
            case SDL_QUIT:
                game.gameState = GAMESTATE::QUIT;
                break;
        }
        game.render(background, 0, 0, 640, 512, 0, 0, 640, 512, 0);
        game.render(balloon, 0, 0, 415, 465, 300, 200, 415/6, 465/6, 0);
        game.render(shield, 0, 0, 353, 707, 300, 300, 353/10, 707/10, -90);
        game.render(ls.laser_texture, 0, 0, 860, 229, ls.x, ls.y, 860/12, 229/12, ls.angle);

        ls.update();
        game.update();
    }

    return 0;
}
