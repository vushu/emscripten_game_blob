#pragma once
#include <cstdint>
#include <entt/entt.hpp>
#include "screen.hpp"

class Movement {
public:
    void update(float dt, entt::registry& registry);
};
