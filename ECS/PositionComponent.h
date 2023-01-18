// GameTest by losimen 18.01.2023

#ifndef GAMETEST_POSITIONCOMPONENT_H
#define GAMETEST_POSITIONCOMPONENT_H

#include "ECS.h"

class PositionComponent: public Component
{
private:
    int xPos;
    int yPos;

public:
    explicit PositionComponent(int x = 0, int y = 0)
    {
        xPos = x;
        yPos = y;
    }

    int x()
    {
        return xPos;
    }

    int y()
    {
        return yPos;
    }

    void init() override
    {
        xPos = 0;
        yPos = 0;
    }

    void update() override
    {
        xPos++;
        yPos++;
    }

    void setPos(int x, int y)
    {
        xPos = x;
        yPos = x;
    }
};
#endif //GAMETEST_POSITIONCOMPONENT_H
