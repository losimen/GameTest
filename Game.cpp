// GameTest by losimen 18.12.2022
#include "Game.h"
#include "Map.h"
#include "ECS/Components.h"

Map *map;

SDL_Renderer *Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());


bool Game::running() const
{
    return isRunning;
}


void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}


void Game::update()
{

    std::cout << player.getComponent<PositionComponent>().x() << ", "
              << player.getComponent<PositionComponent>().y() << std::endl;

    manager.update();
}


void Game::render()
{
    SDL_RenderClear(renderer);

    map->drawMap();
    manager.draw();

    SDL_RenderPresent(renderer);
}


Game::Game(const char *title, int xPos, int yPos, int width, int height, int fullScreen)
{
    Uint32 flags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        isRunning = false;
        return;
    }

    std::cout << "Init subsystems." << std::endl;

    if (fullScreen)
    {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if (window == nullptr)
    {
        std::cout << "Window creation error. " << std::endl;
        isRunning = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr)
    {
        std::cout << "Renderer creation error. " << std::endl;
        isRunning = false;
        return;
    }

    isRunning = true;

    map = new Map();

    player.addComponent<PositionComponent>(100, 500);
    player.addComponent<SpriteComponent>("assets/90.png");
}


Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Terminated" << std::endl;
}
