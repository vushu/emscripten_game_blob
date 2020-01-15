#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
//#ifndef __EMSCRIPTEN__
#include <SDL2/SDL_image.h>
//#endif

#include <iostream>
#include <memory>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

game::World::World()
{
    //std::cout << "World is created " << std::endl;
}

game::World::~World()
{
    SDL_Log("Destroying %s", name.c_str());
}

std::unique_ptr<game::World> game::create_world()
{
    auto world = std::make_unique<World>();
    world->name = "Tu World";
    return world;
}

void game::init_world(std::unique_ptr<World>& game)
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

        int img_flags = IMG_INIT_PNG;

        if (!(IMG_Init(img_flags) & img_flags)) {
            //SDL_Log("");
            std::cout << "FAILED INIT IMG_Load" << std::endl << IMG_GetError() << std::endl;
        } else {
            std::cout << "SUCCESS INIT IMG_Load!" << std::endl;
            //throw "failed to init";
        }
    }
}

void game::update(std::unique_ptr<World>& game)
{
    SDL_Rect strech_rect;
    strech_rect.x = 0;
    strech_rect.y = 0;
    strech_rect.w = SCREEN_WIDTH;
    strech_rect.h = SCREEN_HEIGHT;
    SDL_BlitSurface(game->streched_image, nullptr, game->screen_surface, &strech_rect);
    SDL_UpdateWindowSurface(game->window);
}

SDL_Surface* game::load_surface(std::unique_ptr<World>& game, std::string path)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    } else {
        std::cout << "HAS SURFACE" << std::endl;
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, game->screen_surface->format, 0);
        if (optimizedSurface == nullptr) {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}