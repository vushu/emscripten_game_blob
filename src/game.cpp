#include "game.hpp"
#include "tilemap.hpp"
#include "utils.hpp"
#include <SDL2/SDL_render.h>
#include <memory>

//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_WIDTH = 320;
//const int SCREEN_HEIGHT = 180;
//const int SCREEN_HEIGHT = 480;

void Game::World::create_entities()
{
    //Factories::create_fruit(render.animated_sprites, registry, renderer, Fruit::APPLE, 10, 0);
    //Factories::create_fruit(render.animated_sprites, registry, renderer, Fruit::KIWI, 20, 10);
    //Factories::create_fruit(render.animated_sprites, registry, renderer, Fruit::MELON, 30, 20);
    ////Factories::create_platform(registry, 0.0f, 140.0f, 100.0f, 40.0f);

    //Factories::create_fruit(render.animated_sprites, registry, renderer, Fruit::PINEAPPLE, 30, 50);

    //Factories::create_text(registry, renderer, render.texts, "HEJ", 0.0f, 0.0f);

    tilemap = Tilemap::generate_tilemap();
    tiles = std::make_unique<Texture>(renderer, "resources/Terrain/Terrain.png");
    Factories::create_player(render.animated_sprites, registry, renderer, 30.0, 70.0);

    //Factories::create_camera(registry);
}

Game::World::World()
{
    std::cout << "World is created " << std::endl;
}

Game::World::~World()
{
    SDL_Log("Destroying %s", name.c_str());
}

std::unique_ptr<Game::World> Game::create_world()
{
    auto world = std::make_unique<World>();
    world->name = "Tu World";
    return world;
}

void Game::init_world(std::unique_ptr<World>& game)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL Couldn't %s", SDL_GetError());
        return;
    }
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) {
        printf("Warning: Linear texture filtering not enabled!");
    }
    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    //SDL_GL_SetSwapInterval(1);

    game->window = SDL_CreateWindow("Blob Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!game->window) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "ERROR %s", "");
    } else {
        //SDL_SetHint(SDL_HINT_RENDER_VSYNC, "0");
        //game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
        //game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
        if (!game->renderer) {
            std::cout << "Failed to init sdl renderer" << std::endl;
        } else {
            std::cout << "COOL RENDERER IS CREATED!" << std::endl;
            // SET RENDERER COLOR
            //SDL_RenderSetLogicalSize(game->renderer, 320, 180);
            //SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderSetLogicalSize(game->renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
            // INITIALIZING IMG PNG LOADER
            int img_flags = IMG_INIT_PNG;
            if (!(IMG_Init(img_flags) & img_flags)) {
                //SDL_Log("");
                std::cout << "FAILED INIT IMG_Load" << std::endl
                          << IMG_GetError() << std::endl;
                //exit(1);

                throw std::runtime_error("failed to init img");
            }

            std::cout << "SUCCESS INIT IMG_Load!" << std::endl;
            //if (TTF_Init() == -1) {
            //throw std::runtime_error("failed to init TTF");
            //}

            //std::cout << "TTF INIT SUCCESS!" << std::endl;

            try {
                game->create_entities();

            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

void Game::input(std::unique_ptr<World>& game)
{
}

void Game::update(std::unique_ptr<World>& game, Keyboard& keyboard)
{
    //#ifndef __EMSCRIPTEN__
    //Uint64 start = SDL_GetPerformanceCounter();
    //#endif

    game->player.update(game->delta_time, game->registry, keyboard, game->camera);

    game->consumable_system.update(game->registry);
    game->movement.update(game->delta_time, game->registry);
    game->render.update(game->delta_time, game->registry, game->renderer, game->camera, game->tiles, game->tilemap);
    game->collision_system.update(game->registry, game->tilemap);
    game->gravity_system.update(game->delta_time, game->registry);

    //std::cout << "DT :" << std::endl;
    //std::cout << game->delta_time << std::endl;

    //#ifdef __EMSCRIPTEN__
    //game->delta_time = 0.016f;
    //#else
    //Uint64 end = SDL_GetPerformanceCounter();
    //game->delta_time = 0.016f;
    //game->delta_time = (end - start) / static_cast<float>(SDL_GetPerformanceFrequency());
    //game->delta_time = (end - start) / static_cast<float>(SDL_GetPerformanceFrequency());
    //#endif
}

void Game::close(std::unique_ptr<World>& world)
{
    //SDL_DestroyTexture(world->texture);
    SDL_DestroyRenderer(world->renderer);
    SDL_DestroyWindow(world->window);
    IMG_Quit();
    //TTF_Quit();
    SDL_Quit();
}
