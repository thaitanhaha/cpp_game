#include "gameobject.h"
#include <cmath>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

GameObject::GameObject() 
{
    
}

bool GameObject::CheckCollision(GameObject other)
{
    float epsilon = 40;
    float temp_x = other.position.x + other.texture_offset_x;
    float temp_y = other.position.y + other.texture_offset_y;
    return (fabs(temp_x - position.x) < epsilon) && (fabs(temp_y - position.y) < epsilon);
}