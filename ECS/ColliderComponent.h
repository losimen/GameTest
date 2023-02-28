// GameTest by losimen 20.01.2023

#ifndef GAMETEST_COLLIDERCOMPONENT_H
#define GAMETEST_COLLIDERCOMPONENT_H

#include <string>
#include "SDL.h"
#include "ECS.h"
#include "TransformComponent.h"


class ColliderComponent: public Component
{
public:
    SDL_Rect collider{};
    std::string tag;

    TransformComponent* transform{};

    ColliderComponent(std::string t)
    {
        tag = t;
    }

    void init() override
    {
        if (!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }

        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};


#endif //GAMETEST_COLLIDERCOMPONENT_H
