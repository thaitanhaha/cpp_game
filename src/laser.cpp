#include "laser.h"
#include "shield.h"
#include <cmath>
#include <random>
using namespace std;

Laser::Laser()
{
    this -> position.x = 0;
    this -> position.y = 0;
    this -> angle = 0;
    this -> speed = 0.2;
}

void Laser::RandomStartingPoint(float screenWidth, float screenHeight)
{
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<int> edge(0, 3);
    uniform_real_distribution<float> distribution_x(0.0f, screenWidth);
    uniform_real_distribution<float> distribution_y(0.0f, screenHeight);

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
    this -> position.x = x;
    this -> position.y = y;
}

Laser::Laser(float width, float height, float speed)
{
    ResetLaser(width, height);
    this -> speed = speed;
}

void Laser::update()
{
    this -> position.x += angle_x * speed;
    this -> position.y += angle_y * speed;
}

void Laser::ResetLaser(float width, float height)
{
    RandomStartingPoint(width, height);

    float deltaX = 300.0 - this -> position.x;
    float deltaY = 200.0 - this -> position.y;
    float angleRad = atan2(deltaY, deltaX);
    float angleDeg = angleRad * 180.0f / M_PI;

    this -> angle = angleDeg;

    this -> speed += 0.01;
    if (this -> speed > 0.6)
    {
        this -> speed = 0.6;
    }

    angleRad = angle * M_PI / 180.0f;

    this -> angle_x = cos(angleRad);
    this -> angle_y = sin(angleRad);
}

Laser::~Laser()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}