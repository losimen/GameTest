// GameTest by losimen 28.02.2023

#ifndef GAMETEST_COLLISION_H
#define GAMETEST_COLLISION_H

#include <SDL2/SDL.h>


class Collision
{
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);

};


#endif //GAMETEST_COLLISION_H
