#pragma once
#include <SDL2/SDL_rect.h>
#include <math.h>

class Collision_corners {

public:
    SDL_Point top_left;
    SDL_Point top_right;
    SDL_Point bottom_left;
    SDL_Point bottom_right;
    void calc_corners(float pos_x, float pos_y, float offset_x, float offset_y, float w, float h);
    SDL_Point get_index(float x, float y, int tile_size);
};



