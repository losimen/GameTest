// GameTest by losimen 18.01.2023

#ifndef GAMETEST_ECS_H
#define GAMETEST_ECS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <array>
#include <bitset>


class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeId()
{
    static ComponentID lastID = 0;
    return ++lastID;
}

template <typename T>
inline ComponentID getComponentTypeId() noexcept
{
    static ComponentID typeID = getComponentTypeId();
    return typeID;
}


constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;


class Component
{
public:
    Entity *entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};


class Entity
{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;

public:
    void update()
    {
        for (auto &c: components)
            c->update();
    }

    void draw()
    {
        for (auto &c: components)
            c->draw();
    }

    bool isActive() const
    {
        return active;
    }

    void destroy()
    {
        active = false;
    }

    template<typename T>
    bool hasComponent() const
    {
        return componentBitSet[getComponentTypeId<T>()];
    }

    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr { c };
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeId<T>()] = c;
        componentBitSet[getComponentTypeId<T>()] = true;

        c->init();

        return *c;
    }

    template<typename T>
    T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeId<T>()]);
        return *static_cast<T*>(ptr);
    }
};


class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update()
    {
        for (auto& e: entities)
            e->update();
    }

    void draw()
    {
        for (auto& e: entities)
            e->draw();
    }

    void refresh()
    {
        entities.erase(std::remove_if(entities.begin(), entities.end(),
                                      [](const std::unique_ptr<Entity> &mEntity)
                                      {
                                          return !mEntity->isActive();
                                      }), entities.end());
    }

    Entity& addEntity()
    {
        auto *e = new Entity();
        std::unique_ptr<Entity> uPtr { e };
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};


#endif //GAMETEST_ECS_H
