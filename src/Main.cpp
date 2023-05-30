#include <SDL.h>
#include <iostream>
#include <random>
#include "game.h"
#include "shield.h"
#include "laser.h"
#include "balloon.h"
#include <vector>
#include <chrono>
#include <ctime>    
using namespace std;

const int screenWidth = 640;
const int screenHeight = 512;

int main(int argc, char *argv[])
{
    GameManager game;

    game.init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    SDL_Texture* background = game.loadTexture("sprite/background.png");

    Balloon balloon(300, 200);
    balloon.texture = game.loadTexture("sprite/balloon.png");

    Shield shield;
    shield.texture = game.loadTexture("sprite/shield.png");

    Laser ls(screenWidth, screenHeight, 0.1);
    ls.texture = game.loadTexture("sprite/laser.png");

    int frame = 0;

    auto start = chrono::system_clock::now();

    while (game.gameState != GAMESTATE::QUIT)
    {
        // frame++;
        // if (frame == 1000)
        // {
        //     frame = 0;
        //     ls.ResetLaser(screenWidth, screenHeight, 0.1);
        // }

        SDL_Event windowEvent;
        SDL_PollEvent(&windowEvent);
        switch (windowEvent.type)
        {
            case SDL_QUIT:
                game.gameState = GAMESTATE::QUIT;
                break;
            case SDL_KEYDOWN:
                switch (windowEvent.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        shield.turn("RIGHT");
                        break;
                    case SDLK_UP:
                        shield.turn("UP");
                        break;
                    case SDLK_LEFT:
                        shield.turn("LEFT");
                        break;
                    case SDLK_DOWN:
                        shield.turn("DOWN");
                        break;
                }
                break;
        }
        game.render(background, 0, 0, 640, 512, Position(0, 0), 640, 512, 0);
        game.render(balloon.texture, 0, 0, 415, 465, balloon.position, 415/6, 465/6, 0);
        game.render(shield.texture, 0, 0, 648, 200, shield.position, 648/10, 200/10, shield.angle);
        game.render(ls.texture, 0, 0, 860, 229, ls.position, 860/12, 229/12, ls.angle);
        ls.update();
        game.update();
        if (ls.CheckCollision(shield))
        {
            ls.ResetLaser(screenWidth, screenHeight, 0.1);
        }
        if (ls.CheckCollision(balloon))
        {
            game.gameState = GAMESTATE::QUIT;
        }
    }

    auto end = chrono::system_clock::now();
 
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);
 
    std::cout << "Play time: " << (int) (elapsed_seconds.count()) << "s" << endl;

    return 0;
}
