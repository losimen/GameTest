// GameTest by losimen 20.12.2022

#ifndef GAMETEST_TEXTUREMANAGER_H
#define GAMETEST_TEXTUREMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


class TextureManager
{
public:
    static SDL_Texture *loadTexture(const char *fileName, SDL_Renderer *renderer);

};


#endif //GAMETEST_TEXTUREMANAGER_H
