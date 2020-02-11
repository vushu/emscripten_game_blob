#include "gravity_system.hpp"
#include "components.hpp"
#include <algorithm>

void Gravity_system::update(float dt, entt::registry& registry)
{

    const auto& view = registry.view<Player, Position, Velocity>();

    for (const auto& entity : view) {

        auto& vel = view.get<Velocity>(entity);
        //auto& vel = view.get<Position>(entity);
        vel.dy = std::clamp(vel.dy + 0.2f, 0.0f, 4.0f);
        //vel.y += 0.4f;
    }
};
