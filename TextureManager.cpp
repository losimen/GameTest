// GameTest by losimen 20.12.2022
#include "TextureManager.h"


SDL_Texture *TextureManager::loadTexture(const char *textureFileName, SDL_Renderer *renderer)
{
    SDL_Surface *tempSurface = IMG_Load(textureFileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
