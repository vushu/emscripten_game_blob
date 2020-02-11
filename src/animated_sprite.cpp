#include "animated_sprite.hpp"

Animated_sprite::Animated_sprite(SDL_Renderer* renderer, std::string texture_file, int number_of_frames, float width, float height)
{
    texture = std::make_unique<Texture>(renderer, texture_file);
    Animated_sprite::number_of_frames = number_of_frames;
    clip.w = static_cast<int>(width);
    clip.h = static_cast<int>(height);
    clip.y = 0;
}

Animated_sprite::~Animated_sprite() {}

void Animated_sprite::animate(float x, float y, int delay_per_frame, int offset_x = 0, int offset_y = 0, bool flip = false)
{
    int frame = (SDL_GetTicks() / delay_per_frame) % number_of_frames;
    clip.x = frame * offset_x;
    clip.y = frame * offset_y;

    texture->draw(x, y, &clip, flip);

    if ((frame / number_of_frames) >= delay_per_frame) {
        frame = 0;
    }
}

