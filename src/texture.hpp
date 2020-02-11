#pragma once
//#include "utils.hpp"
//#include <SDL.h>
//#include <SDL_image.h>
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

    void set_color(Uint8 red, Uint8 green, Uint8 blue);
    void set_blend_mode(SDL_BlendMode blending);
    void set_alpha(Uint8 alpha);
    void draw(float x, float y);
    void draw(float x, float y, SDL_Rect* clip);
    void draw(float x, float y, SDL_Rect* clip, bool flip);

    float width;
    float height;

private:
    std::string filename;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};
