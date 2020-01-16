#pragma once
#include "utils.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <string>

class Texture {
public:
    // constructors, asssignment, destructor
    Texture(SDL_Renderer* renderer, std::string path);
    ~Texture();

    void free();

    void render(int x, int y);

    int width;
    int height;

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};
