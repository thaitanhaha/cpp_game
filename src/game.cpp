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
    display();
    clear();
}

void GameManager::init(const char* title, int x, int y, int width, int height, Uint32 flags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

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

void GameManager::render(SDL_Texture* tex, int src_x, int src_y, int src_w, int src_h, 
                            int dst_x, int dst_y, int dst_w, int dst_h, int angle)
{
    SDL_Rect src;
    src.x = src_x;
    src.y = src_y;
    src.w = src_w;
    src.h = src_h;

    SDL_Rect dst;
    dst.x = dst_x;
    dst.y = dst_y;
    dst.w = dst_w;
    dst.h = dst_h;
    SDL_RenderCopyEx(renderer, tex, &src, &dst, angle, NULL, SDL_FLIP_NONE);
}