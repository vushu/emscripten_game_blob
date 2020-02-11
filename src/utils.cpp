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

SDL_Texture* Utils::load_texture(SDL_Renderer* renderer, std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

SDL_Rect Utils::create_top_left_rect(const int width, const int height)
{
    SDL_Rect top_left_rect;
    top_left_rect.x = 0;
    top_left_rect.y = 0;
    top_left_rect.w = width / 2;
    top_left_rect.h = height / 2;
    return top_left_rect;
}

SDL_Rect Utils::create_top_right_rect(const int width, const int height)
{
    SDL_Rect top_right_rect;
    top_right_rect.x = width / 2;
    top_right_rect.y = 0;
    top_right_rect.w = width / 2;
    top_right_rect.h = height / 2;
    return top_right_rect;
}



SDL_Rect Utils::create_bottom_rect(const int width, const int height)
{
    SDL_Rect bottom_rect;
    bottom_rect.x = 0;
    bottom_rect.y = height/2;
    bottom_rect.w = width;
    bottom_rect.h = height / 2;
    return bottom_rect;
}
