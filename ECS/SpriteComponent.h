// GameTest by losimen 18.01.2023

#ifndef GAMETEST_SPRITECOMPONENT_H
#define GAMETEST_SPRITECOMPONENT_H

#include "SDL.h"

class SpriteComponent: public Component
{
private:
    TransformComponent *transform{};
    SDL_Texture *texture{};
    SDL_Rect srcRect{}, destRect{};

public:
    SpriteComponent() = default;
    explicit SpriteComponent(const char* path)
    {
        texture = TextureManager::loadTexture(path);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }

    void setTex(const char *path)
    {
        texture = TextureManager::loadTexture(path);
    }

    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }

    void draw() override
    {
        TextureManager::draw(texture, srcRect, destRect);
    }
};


#endif //GAMETEST_SPRITECOMPONENT_H
