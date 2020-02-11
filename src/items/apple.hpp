#pragma once
#include "../texture.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>
#include <memory>
class Apple {

public:
    Apple(SDL_Renderer* renderer);
    ~Apple();

    void animate(int x, int y);

private:
    SDL_Renderer* renderer;
    SDL_Rect clip;
    //int frame = 0;
    int delay_per_frame = 50;
    std::unique_ptr<Texture> texture;
};
