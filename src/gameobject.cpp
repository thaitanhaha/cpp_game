#include "gameobject.h"
#include <cmath>

GameObject::GameObject() 
{
    
}

bool GameObject::CheckCollision(GameObject other)
{
    float epsilon = 30;
    return (fabs(position.x - other.position.x) < epsilon) && (fabs(position.y - other.position.y) < epsilon);
}
