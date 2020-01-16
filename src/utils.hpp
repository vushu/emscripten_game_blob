#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <memory>
#include <iostream>
#include <SDL2/SDL_image.h>

namespace Utils {
    SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);
    SDL_Surface* load_surface(SDL_Surface& screen_surface, std::string path);
    SDL_Rect create_top_left_rect(const int width, const int height);
    SDL_Rect create_top_right_rect(const int width, const int height);
    SDL_Rect create_bottom_rect(const int width, const int height);
};
