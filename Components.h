// GameTest by losimen 18.01.2023

#ifndef GAMETEST_COMPONENTS_H
#define GAMETEST_COMPONENTS_H

#include "ECS.h"

class PositionComponent: public Component
{
private:
    int xPos;
    int yPos;

public:
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

#endif //GAMETEST_COMPONENTS_H
