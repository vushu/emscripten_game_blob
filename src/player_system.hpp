#pragma once
#include "components.hpp"
#include "keyboard.hpp"
#include <entt/entt.hpp>
#include <iostream>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_stdinc.h>

#include <map>
enum Player_states {
    RUNNING,
    IDLE,
    JUMP,
    FALLING,
};

class Player_system {
public:
    std::map<Player_states, entt::entity> entities;
    void change_state(Player_states states);
    void update(float dt, entt::registry& registry, Keyboard& keyboard, SDL_Rect& camera);
};
