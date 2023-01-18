// GameTest by losimen 20.12.2022
#include "GameObject.h"

GameObject::GameObject(const char *textureFileName, SDL_Renderer *renderer, int x, int y)
{
    this->renderer = renderer;
    objTexture = TextureManager::loadTexture(textureFileName, renderer);

    xPos = x;
    yPos = y;
}


void GameObject::update()
{
    xPos++;
    yPos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.h = 32;
    destRect.w = 32;
}

void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, nullptr, &destRect);
}
