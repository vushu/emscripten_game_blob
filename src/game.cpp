#include "game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_log.h>
//#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
//#ifndef __EMSCRIPTEN__
#include <SDL2/SDL_image.h>
//#endif

#include <SDL2/SDL_video.h>
#include <iostream>
#include <memory>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game::World::World()
{
    //std::cout << "World is created " << std::endl;
}

Game::World::~World()
{
    SDL_Log("Destroying %s", name.c_str());
}

std::unique_ptr<Game::World> Game::create_world()
{
    auto world = std::make_unique<World>();
    world->name = "Tu World";
    return world;
}

void Game::init_world(std::unique_ptr<World>& game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL Couldn't %s", SDL_GetError());
        return;
    }

    game->window = SDL_CreateWindow("SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!game->window) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "ERROR %s", "");
    } else {

        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
        if (!game->renderer) {
            std::cout << "Failed to init sdl renderer" << std::endl;
        } else {

            std::cout << "COOL RENDERER IS CREATED!" << std::endl;
            // SET RENDERER COLOR
            SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            // INITIALIZING IMG PNG LOADER
            int img_flags = IMG_INIT_PNG;
            if (!(IMG_Init(img_flags) & img_flags)) {
                //SDL_Log("");
                std::cout << "FAILED INIT IMG_Load" << std::endl
                          << IMG_GetError() << std::endl;
                exit(1);
            } else {
                std::cout << "SUCCESS INIT IMG_Load!" << std::endl;
                //game->screen_surface = SDL_GetWindowSurface(game->window);
            }
        }
    }
}

void Game::update(std::unique_ptr<World>& game)
{
    SDL_Rect strech_rect;
    strech_rect.x = 0;
    strech_rect.y = 0;
    strech_rect.w = SCREEN_WIDTH;
    strech_rect.h = SCREEN_HEIGHT;
    SDL_BlitSurface(game->streched_image, nullptr, game->screen_surface, &strech_rect);
    SDL_UpdateWindowSurface(game->window);
}
