#include "laser.h"
#include <cmath>
#include <random>
using namespace std;

Laser::Laser()
{
    this -> x = 0;
    this -> y = 0;
    this -> angle = 0;
    this -> speed = 0.06;
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
    this -> x = x;
    this -> y = y;
}

Laser::Laser(float width, float height, float speed)
{
    ResetLaser(width, height, speed);
}

void Laser::update()
{
    x += angle_x * speed;
    y += angle_y * speed;
}

void Laser::ResetLaser(float width, float height, float speed)
{
    RandomStartingPoint(width, height);

    float deltaX = 300.0 - x;
    float deltaY = 200.0 - y;
    float angleRad = atan2(deltaY, deltaX);
    float angleDeg = angleRad * 180.0f / M_PI;

    this -> angle = angleDeg;
    this -> speed = speed;

    angleRad = angle * M_PI / 180.0f;

    this -> angle_x = cos(angleRad);
    this -> angle_y = sin(angleRad);
}

Laser::~Laser()
{
    if (laser_texture != nullptr)
    {
        SDL_DestroyTexture(laser_texture);
        laser_texture = nullptr;
    }
}