#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <memory>
#include "game.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

namespace Utils {
    SDL_Texture* load_texture(std::string path);
    SDL_Surface* load_surface(SDL_Surface& screen_surface, std::string path);
};
