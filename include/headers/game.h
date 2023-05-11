#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

enum GAMESTATE {
    RUNNING,
    QUIT,
};

class GameManager 
{
    private:
        // void update();
        // void handleEvents();

        SDL_Window* window;
        SDL_Renderer* renderer;


        void clear();
        void display();
        void cleanup();
        
    public:
        GAMESTATE gameState;
        SDL_Texture* loadTexture(const char*);
        GameManager();
        ~GameManager();
        void init(const char*, int, int, int, int, Uint32);
        void update();
        void render(SDL_Texture*, int, int, int, int);
};