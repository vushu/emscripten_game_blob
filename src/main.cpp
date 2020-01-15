#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <memory>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

static bool quit = false;
static std::unique_ptr<Game::World> world;

void main_loop()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_ESCAPE) {
                quit = true;
                SDL_Log("END");
            }
        }
        Game::update(world);
    }
}

int main()
{

    world = Game::create_world();
    Game::init_world(world);
    //std::cout << "GAME STARTET!" << std::endl;
    //emscripten_log(a, "hej");

#ifdef __EMSCRIPTEN__
    // 0 fps means to use requestAnimationFrame; non-0 means to use setTimeout.
    emscripten_set_main_loop(main_loop, 0, 1);
#else
    while (!quit) {
        main_loop();
        SDL_Delay(16);
    }
#endif

    SDL_FreeSurface(world->screen_surface);
    SDL_DestroyWindow(world->window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}
