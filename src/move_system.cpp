#include "move_system.hpp"
#include "components.hpp"

void Movement::update(float dt, entt::registry& registry)
{
    //std::cout << dt << std::endl;
    registry.view<Position, Velocity>().each([dt](auto& pos, auto& vel) {
        //std::cout << dt << std::endl;
        //pos.x += vel.dx * dt;
        //pos.y += vel.dy * dt;
        pos.x += vel.dx;
        pos.y += vel.dy;
    });
}
