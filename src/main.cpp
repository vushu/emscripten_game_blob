#include "game.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

static bool quit = false;
static std::unique_ptr<game::World> world;

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
        game::update(world);
    }
}

int main()
{

    world = game::create_world();
    game::init_world(world);
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
    SDL_Quit();

    return 0;
}
