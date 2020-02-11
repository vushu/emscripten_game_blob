#pragma once

#include "components.hpp"
#include <entt/entt.hpp>
#include <iostream>
class Consumable_system {

public:
    void update(entt::registry& registry);

    bool collided(int x, int y, int w, int h, int x2, int y2, int w2, int h2);
};
