// GameTest by losimen 20.12.2022

#ifndef GAMETEST_GAMEOBJECT_H
#define GAMETEST_GAMEOBJECT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "TextureManager.h"


class GameObject
{
private:
    int xPos;
    int yPos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect{}, destRect{};

public:
    explicit GameObject(const char *textureFileName, int x = 0, int y = 0);

    void update();
    void render();
};


#endif //GAMETEST_GAMEOBJECT_H
