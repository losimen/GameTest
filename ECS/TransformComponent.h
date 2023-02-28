// GameTest by losimen 18.01.2023

#ifndef GAMETEST_TRANSFORMCOMPONENT_H
#define GAMETEST_TRANSFORMCOMPONENT_H

#include "ECS.h"
#include "../Vector2D.h"

class TransformComponent: public Component
{
public:
    Vector2D position;
    Vector2D velocity;

    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;

    TransformComponent()
    {
        position.x = 0;
        position.y = 0;
    }

    explicit TransformComponent(int sc)
    {
        position.x = 0;
        position.y = 0;

        scale = sc;
    }

    explicit TransformComponent(float x, float y)
    {
        position.x = y;
        position.y = x;
    }

    explicit TransformComponent(float x, float y, int h, int w, int s)
    {
        position.x = y;
        position.y = x;
        height = h;
        width = w;
        scale = s;
    }

    void init () override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};
#endif //GAMETEST_TRANSFORMCOMPONENT_H
