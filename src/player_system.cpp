#include "player_system.hpp"
#include "components.hpp"
#include "screen.hpp"

static bool flipped = false;
static bool jumping = false;
static float jump_time = 0.0f;
static float speed = 0.05f;
static Uint32 jump_t = 0;
static int jump_frames = 0;
static bool not_released = false;
void Player_system::update(float dt, entt::registry& registry, Keyboard& keyboard, SDL_Rect& camera)
{
    const auto& view = registry.view<Player, Position, Sprite, Velocity>();

    for (const auto& entity : view) {
        auto& position = view.get<Position>(entity);
        auto& player = view.get<Player>(entity);
        //auto& position = view.get<Velocity>(entity);
        if (jumping) {
            registry.assign_or_replace<Sprite>(entity, "jump", flipped);
        }
        camera.x = (position.x + 32 / 2) - SCREEN_WIDTH / 2 + 24;
        camera.y = (position.y + 32 / 2) - SCREEN_HEIGHT / 2;
        //position.x = keyboard.mouse_x;
        //position.y = keyboard.mouse_y;
        auto& vel
            = view.get<Velocity>(entity);
        if (keyboard.right) {
            flipped = false;
            if (!jumping)
                registry.assign_or_replace<Sprite>(entity, "run");
            else
                registry.assign_or_replace<Sprite>(entity, "jump", flipped);
            vel.dx = std::clamp(vel.dx + speed, 1.0f, 2.f);
        }
        if (keyboard.left) {
            flipped = true;
            if (!jumping)
                registry.assign_or_replace<Sprite>(entity, "run", flipped);
            else
                registry.assign_or_replace<Sprite>(entity, "jump", flipped);

            vel.dx = std::clamp(vel.dx - speed, -2.f, -1.0f);
        }
        if (keyboard.jump && player.on_ground && !jumping) {

            player.on_ground = false;
            jumping = true;
            jump_frames = 0;
            not_released = true;
            //} else
            //jump_t = 0;
        }
        if (!keyboard.jump) {
            not_released = false;
        }
        // not pretty,but get the job done
        if (keyboard.jump && !player.on_ground && jumping && not_released) {
            if (jump_frames < 15)
                vel.dy = std::clamp(vel.dy - 7.0f, -10.0f, 0.0f);
            //std::cout << jump_frames << std::endl;
            jump_frames++;
        }
        if (player.on_ground) {
            jumping = false;
        }
        if (!jumping && !keyboard.left && !keyboard.right) {
            registry.assign_or_replace<Sprite>(entity, "idle", flipped);
            vel.dx = 0;
        }
    }
}
