//#include "SDL_timer.h"
#include "components.hpp"
#include "game.hpp"
#include "render_system.hpp"
#include "screen.hpp"
#include "utils.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include <cstdio>
#include <iostream>
#include <memory>
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

static bool quit = false;
static bool is_fullscreen = false;
static std::unique_ptr<Game::World> world;
static Keyboard keyboard;
static float elapsed = 0.0f;
static Uint64 start = 0;
static Uint64 end = 0;
static int frame_counter = 0;

void handle_events()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        keyboard.mouse_x = x;
        keyboard.mouse_y = y;

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

        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_f) {
                is_fullscreen = !is_fullscreen;
                int flag = is_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
                SDL_SetWindowFullscreen(world->window, flag);
            }
        }
        if (e.type == SDL_KEYDOWN) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_d) {
                keyboard.right = true;
            }
        }
        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_d) {
                keyboard.right = false;
            }
        }

        if (e.type == SDL_KEYDOWN) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_a) {
                keyboard.left = true;
            }
        }
        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_a) {
                keyboard.left = false;
            }
        }
        if (e.type == SDL_KEYDOWN) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_SPACE) {
                keyboard.jump = true;
            }
        }

        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
            if (sym == SDLK_SPACE) {
                keyboard.jump = false;
            }
        }

        if (e.type == SDL_KEYUP) {
            int sym = e.key.keysym.sym;
        }
    }
}

void main_loop()
{
    world->cap_timer.start();
    handle_events();
    Game::update(world, keyboard);

    float avgFPS = world->counted_frames / (world->fps_timer.getTicks() / 1000.f);

    if (avgFPS > 2000000) {
        avgFPS = 0;
    }

    //std::cout << avgFPS << std::endl;

    int frameTicks = world->cap_timer.getTicks();
    if (frameTicks < SCREEN_TICKS_PER_FRAME) {
        //Wait remaining time
        SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
    }
    ++world->counted_frames;
}

int numFrames = 0;
int startTime = 0;

void printFps()
{
    int elapsedMS = SDL_GetTicks() - startTime; // Time since start of loop
    ++numFrames;
    if (elapsedMS) {
        double elapsedSeconds = elapsedMS / 1000.0; // Convert to seconds
        double fps = numFrames / elapsedSeconds;    // FPS is Frames / Seconds
        printf("%s %f\n", "FPS: ", fps);
        //printf("%s %d\n", "dt: ", elapsedMS);
        //printf("%s %d\n", "secs: ", elapsedSeconds);
    }
}
int main()
{
    world = Game::create_world();
    Game::init_world(world);
    world->delta_time = 1;
    world->fps_timer.start();

#ifdef __EMSCRIPTEN__
    // 0 fps means to use requestAnimationFrame; non-0 means to use setTimeout.
    emscripten_set_main_loop(main_loop, 0, 1);
    //emscripten_set_main_loop(printFps, -1, 1);
#else
    while (!quit) {
        main_loop();

        //printFps();
        //SDL_Delay(16);
    }
#endif

    // not using surface since we are using renderer which is performing on the GPU
    //SDL_FreeSurface(world->screen_surface);
    Game::close(world);

    return 0;
}
