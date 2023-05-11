#include <SDL.h>
#include <iostream>
#include "game.h"
using namespace std;

const int screenWidth = 640;
const int screenHeight = 512;

int main(int argc, char *argv[])
{
    GameManager game;
    
    game.init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    SDL_Texture* background = game.loadTexture("background.png");

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
        game.render(background, 640, 512, 640, 512);
        game.update();
    }

    return 0;
}


// const int WIDTH = 800, HEIGHT = 600;

// const int WIDTH = 640, HEIGHT = 360;

// int main( int argc, char *argv[] )
// {
//     SDL_Surface *imageSurface = NULL;
//     SDL_Surface *windowSurface = NULL;
    
//     if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
//     {
//         std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError( ) << std::endl;
//     }
    
//     SDL_Window *window = SDL_CreateWindow( "My game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
//     windowSurface = SDL_GetWindowSurface( window );
    
//     SDL_Event windowEvent;
    
//     imageSurface = SDL_LoadBMP( "hello_world.bmp" );
//     if( imageSurface == NULL )
//     {
//         std::cout << "SDL could not load image! SDL Error: " << SDL_GetError( ) << std::endl;
//     }
    
//     while ( true )
//     {
//         if ( SDL_PollEvent( &windowEvent ) )
//         {
//             if ( SDL_QUIT == windowEvent.type )
//             {
//                 break;
//             }
//         }
        
//         SDL_BlitSurface( imageSurface, NULL, windowSurface, NULL );
        
//         SDL_UpdateWindowSurface( window );
//     }
    
//     SDL_FreeSurface( imageSurface );
//     SDL_FreeSurface( windowSurface );
    
//     imageSurface = NULL;
//     windowSurface = NULL;
    
//     SDL_DestroyWindow( window );
//     SDL_Quit( );
    
//     return EXIT_SUCCESS;
// }
