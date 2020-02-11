#include "consumable_system.hpp"

bool Consumable_system::collided(int x, int y, int w, int h, int x2, int y2, int w2, int h2)
{
    if (x < x2 + w2 && x + w > x2 && y < y2 + h2 && y + h > y2) {
        return true;
    }
    return false;
}

void Consumable_system::update(entt::registry& registry)
{

    const auto& view = registry.view<Player, Collision, Position>();
    const auto& vi = registry.view<Consumable, Position, Collision>();
    for (auto& entity : view) {
        auto& player_collision = view.get<Collision>(entity);
        auto& player_position = view.get<Position>(entity);
        for (auto& en : vi) {
            auto& consumable_collision = vi.get<Collision>(en);
            auto& consumable_position = vi.get<Position>(en);
            //std::cout << "HERE" << player_position.y << std::endl;
            //std::cout << "HERE" << consumable_position.x << std::endl;
            bool res = collided(player_position.x, player_position.y, player_collision.w, player_collision.h, consumable_position.x, consumable_position.y, consumable_collision.w, consumable_collision.h);
            if (res) {
                registry.destroy(en);
            }
        }
    }
}
