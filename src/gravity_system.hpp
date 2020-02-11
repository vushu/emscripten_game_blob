#pragma once

#include <entt/entt.hpp>
#include "components.hpp"
class Gravity_system {

public:
    void update(float dt, entt::registry& registry);
};
