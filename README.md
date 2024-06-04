# Block the Laser

## Introduction
Block the Laser is a 2D game assignment made in the HCMUT Advanced Programming Extra Course.

## How to play

The player must change the direction of the shield to block the lasers being fired from the edge of screen with random direction. 

+ Rotate the shield: Up/Down/Left/Right Arrow
The gameplay is just relax, which means there is no score.

## Implement
Beside basic C++ and OOP, I used SDL2 to handle with the input from keyboard. 
+ SDL (Simple DirectMedia Layer) is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. 

## Build
I used Makefile to compile and build the game. 
```
g++ -Iinclude -Iinclude / sdl -Iinclude / headers -Llib -o Main src /*. cpp -
lmingw32 -lSDL2main -lSDL2 - lSDL2_image
```
After running `make` in terminal, there is a `.exe` file appeared. Just double click it to play the game.

## Demo 
![alt](/demo.png)

## Comment 
I did not handle the pivot and position of the objects well so that the shield still has bugs.
