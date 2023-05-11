#include "game.h"

GameManager::GameManager() 
{
    window = NULL;
    renderer = NULL;
    gameState = GAMESTATE::RUNNING;
}

GameManager::~GameManager()
{

}

void GameManager::update()
{
    // init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    display();
    clear();
}

void GameManager::init(const char* title, int x, int y, int width, int height, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

// void GameManager::update()
// {
//     while (gameState != GAMESTATE::QUIT)
//     {
//         display();
//         clear();
//         handleEvents();
//     }
// }


SDL_Texture* GameManager::loadTexture(const char* filePath)
{
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(renderer, filePath);
    return tex;
}

void GameManager::display()
{
    SDL_RenderPresent(renderer);
}

void GameManager::clear()
{
    SDL_RenderClear(renderer);
}

void GameManager::cleanup()
{
    SDL_DestroyWindow(window);
}

void GameManager::render(SDL_Texture* tex, int src_w, int src_h, int dst_w, int dst_h)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = src_w;
    src.h = src_h;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = dst_w;
    dst.h = dst_h;
    SDL_RenderCopy(renderer, tex, &src, &dst);
}