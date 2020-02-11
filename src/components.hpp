#pragma once

#include "animated_sprite.hpp"
#include <entt/entt.hpp>
#include <string>

struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};

//sprite tag
struct Sprite {
    std::string name;
    bool flip = false;
};

struct Collision {
    float w, h;
    float offset_x, offset_y;
};

struct Consumable {
};

struct Solid {
};

//Player tag
struct Player {
    bool on_ground = false;
};

struct Debug_text {
    std::string text;
};

struct Camera {
    int x;
    int y;
};
