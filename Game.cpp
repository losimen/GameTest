// GameTest by losimen 18.12.2022
#include "Game.h"


SDL_Texture *playerTex;
SDL_Rect srcR, destR;
unsigned cnt;


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
    cnt++;
    destR.h = 32;
    destR.w = 32;
    destR.x = cnt;

    std::cout << cnt << std::endl;
}


void Game::render()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, playerTex, nullptr, &destR);

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
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    if(renderer == nullptr)
    {
        std::cout << "Renderer creation error. " << std::endl;
        isRunning = false;
        return;
    }

    isRunning = true;

    playerTex = TextureManager::loadTexture("assets/90.png", renderer);
}


Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Terminated" << std::endl;
}
