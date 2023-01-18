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
    SDL_Rect srcRect, destRect;

    SDL_Renderer *renderer;

public:
    GameObject(const char *textureFileName, SDL_Renderer *renderer, int x = 0, int y = 0);

    void update();
    void render();
};


#endif //GAMETEST_GAMEOBJECT_H
