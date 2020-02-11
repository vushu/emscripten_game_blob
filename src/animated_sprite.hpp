#pragma once
#include "texture.hpp"
#include <entt/entt.hpp>
#include <iostream>
#include <memory>

class Animated_sprite {

public:
    Animated_sprite(SDL_Renderer* renderer, std::string texture_file, int number_of_frames, float width, float height);
    ~Animated_sprite();
    void animate(float x, float y, int delay_per_frame, int offset_x, int offset_y, bool flip);

private:
    SDL_Renderer* renderer;
    SDL_Rect clip;
    int number_of_frames;

    std::unique_ptr<Texture> texture;
};
