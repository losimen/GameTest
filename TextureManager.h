// GameTest by losimen 20.12.2022

#ifndef GAMETEST_TEXTUREMANAGER_H
#define GAMETEST_TEXTUREMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


class TextureManager
{
public:
    static SDL_Texture *loadTexture(const char *textureFileName);
    static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};


#endif //GAMETEST_TEXTUREMANAGER_H
