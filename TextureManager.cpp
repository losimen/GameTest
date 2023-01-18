// GameTest by losimen 20.12.2022
#include "TextureManager.h"
#include "Game.h"

SDL_Texture *TextureManager::loadTexture(const char *textureFileName)
{
    SDL_Surface *tempSurface = IMG_Load(textureFileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
