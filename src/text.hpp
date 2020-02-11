#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <SDL2/SDL_ttf.h>

#include <cmath>
#include <iostream>
#include <string>

class Text {
public:
    Text(SDL_Renderer* renderer, std::string text, int size);
    ~Text();
    void render(float x, float y);
    float width, height;

private:
    SDL_Renderer* renderer;
    //TTF_Font* font;
    SDL_Texture* texture;
};
