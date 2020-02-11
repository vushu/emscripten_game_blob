#pragma once
#include "animated_sprite.hpp"
#include "collision_system.hpp"
#include "components.hpp"
#include "factories.hpp"
#include "texture.hpp"
#include "utils.hpp"

#include "consumable_system.hpp"
#include "gravity_system.hpp"
#include "items/apple.hpp"
#include "move_system.hpp"
#include "player_system.hpp"
#include "render_system.hpp"

#include "keyboard.hpp"
#include "timer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
//#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <entt/entt.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>

namespace Game {

class World {
private:
public:
    SDL_Window* window;
    SDL_Renderer* renderer = nullptr;
    // systems
    SDL_Rect camera;
    Render render;
    Movement movement;
    Player_system player;
    Gravity_system gravity_system;
    Consumable_system consumable_system;
    Collision_system collision_system;
    LTimer fps_timer;
    LTimer cap_timer;
    LTimer delta_timer;
    std::stringstream time_text;
    int counted_frames = 0;

    float delta_time = 0;

    std::unique_ptr<Texture> tiles;
    std::unique_ptr<Animated_sprite> apple;
    std::unique_ptr<Texture> background;
    std::string name;

    std::vector<std::vector<int>> tilemap;

    entt::registry registry;
    int frame;
    World();
    ~World();
    void create_entities();
};

const int SCREEN_WIDTH = 320;
//const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 180;
//const int SCREEN_HEIGHT = 600;

void init_world(std::unique_ptr<World>& game);
void input(std::unique_ptr<World>& game);
void update(std::unique_ptr<World>& game, Keyboard& keyboard);
void cleanup(std::unique_ptr<World>& game);
void draw(std::unique_ptr<World>& game);
void close(std::unique_ptr<World>& game);

std::unique_ptr<World> create_world();
std::unique_ptr<World> create_world_unique();
}
