#include "game.hpp"
#include "SDL_render.h"
#include "utils.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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

    game->window = SDL_CreateWindow("SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!game->window) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "ERROR %s", "");
    } else {

        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
        if (!game->renderer) {
            std::cout << "Failed to init sdl renderer" << std::endl;
        } else {

            std::cout << "COOL RENDERER IS CREATED!" << std::endl;
            // SET RENDERER COLOR
            SDL_SetRenderDrawColor(game->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            // INITIALIZING IMG PNG LOADER
            int img_flags = IMG_INIT_PNG;
            if (!(IMG_Init(img_flags) & img_flags)) {
                //SDL_Log("");
                std::cout << "FAILED INIT IMG_Load" << std::endl
                          << IMG_GetError() << std::endl;
                exit(1);
            } else {
                std::cout << "SUCCESS INIT IMG_Load!" << std::endl;
                // SHOW TU <3
                game->texture = Utils::load_texture(game->renderer, "resources/Background/Blue.png");
                if (!game->texture) {
                    std::cout << "Failed to load texture" << std::endl;
                }
            }
        }
    }
}

void Game::update(std::unique_ptr<World>& game)
{
    SDL_Rect strech_rect;
    strech_rect.x = 0;
    strech_rect.y = 0;
    strech_rect.w = SCREEN_WIDTH;
    strech_rect.h = SCREEN_HEIGHT;

    //SDL_BlitSurface(game->streched_image, nullptr, game->screen_surface, &strech_rect);
    //
    //SDL_UpdateWindowSurface(game->window);
    //
    // not using above since we are using renderer

    // CLEAR SCREEN
    SDL_RenderClear(game->renderer);

    // VIEWPORT
    auto rect = Utils::create_top_right_rect(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT);
    SDL_RenderSetViewport(game->renderer, &rect);
    // ADDING TEXTURE
    SDL_RenderCopy(game->renderer, game->texture, nullptr, &strech_rect);

    auto rect2 = Utils::create_bottom_rect(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT);
    SDL_RenderSetViewport(game->renderer, &rect2);
    // ADDING TEXTURE
    SDL_RenderCopy(game->renderer, game->texture, nullptr, nullptr);


    //UPDATE SCREEN
    SDL_RenderPresent(game->renderer);
}

void Game::close(std::unique_ptr<World>& world)
{
    SDL_DestroyTexture(world->texture);
    SDL_DestroyRenderer(world->renderer);
    SDL_DestroyWindow(world->window);
    IMG_Quit();
    SDL_Quit();
}
