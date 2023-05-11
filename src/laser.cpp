#include "laser.h"
#include <cmath>

Laser::Laser()
{
    this -> x = 0;
    this -> y = 0;
    this -> angle = 0;
    this -> speed = 0.02;
}

Laser::Laser(float x, float y, float speed)
{
    this -> x = x;
    this -> y = y;

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

void Laser::update()
{
    x += angle_x * speed;
    y += angle_y * speed;
}