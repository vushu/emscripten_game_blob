#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <memory>
#include <string>

namespace Game {

class World {
private:
    // Surface
public:
    SDL_Window* window;
    SDL_Surface* screen_surface = nullptr;
    SDL_Surface* streched_image = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
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
