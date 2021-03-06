#pragma once
#include <memory>
#include <string>
#include <SDL2/SDL.h>

namespace game {

class World {
private:
    // Surface
public:
    SDL_Window* window;
    SDL_Surface* screen_surface;
    std::string name;
    World();
    ~World();

};

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void init_world(std::unique_ptr<World>& game);
void update(std::unique_ptr<World>& game);
void cleanup(std::unique_ptr<World>& game);
void draw(std::unique_ptr<World>& game);
void destroy_window(std::unique_ptr<World>& game);
std::unique_ptr<World> create_world();
std::unique_ptr<World> create_world_unique();
}
