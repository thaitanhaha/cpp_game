#ifndef GAME_H
#define GAME_H 

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "gameobject.h"

enum GAMESTATE {
    RUNNING,
    QUIT,
};

class GameManager 
{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        void clear();
        void display();

    public:
        void cleanup();
        GameManager();
        ~GameManager();

        GAMESTATE gameState;
        
        SDL_Texture* loadTexture(const char*);

        void init(const char*, int, int, int, int, Uint32);
        void update();
        void render(SDL_Texture*, int, int, int, int, Position, int, int, int);
};

#endif