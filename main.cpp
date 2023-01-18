#include "Game.h"


int main()
{
    Game game("Lol", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    unsigned frameStart;
    unsigned frameTime;

    while (game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}
