// GameTest by losimen 18.01.2023

#ifndef GAMETEST_MAP_H
#define GAMETEST_MAP_H

#include "Game.h"


class Map
{
private:
    SDL_Rect src, dest;

    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int map[20][25];
public:
    Map();
    ~Map();

    void loadMap(int arr[20][25]);
    void drawMap();
};


#endif //GAMETEST_MAP_H
