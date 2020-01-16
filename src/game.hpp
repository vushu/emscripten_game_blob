#pragma once
#include "utils.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <memory>

namespace Game {

class World {
private:
    // Surface
public:
    SDL_Window* window;
    //using sdl renderer so surface not needed
    //SDL_Surface* screen_surface = nullptr;
    //SDL_Surface* streched_image = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    std::string name;
    World();
    ~World();
};

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 180;

void init_world(std::unique_ptr<World>& game);
void update(std::unique_ptr<World>& game);
void cleanup(std::unique_ptr<World>& game);
void draw(std::unique_ptr<World>& game);
void close(std::unique_ptr<World>& game);

std::unique_ptr<World> create_world();
std::unique_ptr<World> create_world_unique();
}
