// GameTest by losimen 18.01.2023

#ifndef GAMETEST_TRANSFORMCOMPONENT_H
#define GAMETEST_TRANSFORMCOMPONENT_H

#include "ECS.h"
#include "../Vector2D.h"

class TransformComponent: public Component
{
public:
    Vector2D position;

    TransformComponent()
    {
        position.x = 0;
        position.y = 0;
    }

    explicit TransformComponent(float x = 0, float y = 0)
    {
        position.x = y;
        position.y = x;
    }

    void update() override
    {

    }
};
#endif //GAMETEST_TRANSFORMCOMPONENT_H
