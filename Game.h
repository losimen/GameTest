// GameTest by losimen 18.12.2022

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "TextureManager.h"


class Game
{
private:
    SDL_Window *window;

    bool isRunning;

public:
    static SDL_Event event;

    Game() = delete;
    Game(const char *title, int xPos, int yPos, int width, int height, int fullScreen);

    static SDL_Renderer *renderer;

    void handleEvents();
    void update();
    void render();

    ~Game();

    bool running() const;
};


#endif //GAMETEST_GAME_H
