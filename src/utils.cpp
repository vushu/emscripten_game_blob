#include "utils.hpp"

SDL_Surface* Utils::load_surface(SDL_Surface& screen_surface, std::string path)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    } else {
        std::cout << "HAS SURFACE" << std::endl;
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, screen_surface.format, 0);
        if (optimizedSurface == nullptr) {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}
