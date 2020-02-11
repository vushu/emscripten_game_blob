#include "texture.hpp"
//#include "utils.hpp"
#include <iostream>

Texture::Texture(SDL_Renderer* renderer, std::string path)
{
    Texture::renderer = renderer;
    filename = path;
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());

    if (!loaded_surface) {
        std::cout << "Failed to load texture" << std::endl;
        throw std::runtime_error("Failed to load file: " + path);
    }
    // not neede if colorkey
    //SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);

    if (!new_texture) {
        //std::cout << "Failed to create texture" << std::endl
        //<< SDL_GetError() << std::endl;
        throw std::runtime_error(std::string("Failed to create texture") + path);
    }

    width = loaded_surface->w;
    height = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    texture = new_texture;
}

Texture::~Texture()
{
    free();
}

void Texture::free()
{
    std::cout << "Freed Texture " << filename << std::endl;
    SDL_DestroyTexture(texture);
}

void Texture::set_color(Uint8 red, Uint8 green, Uint8 blue)
{
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::set_alpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::set_blend_mode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::draw(float x, float y)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

void Texture::draw(float x, float y, SDL_Rect* clip)
{
    //Set rendering space and render to screen
    //SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), width, height };
    SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;

    SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

void Texture::draw(float x, float y, SDL_Rect* clip, bool flip)
{
    SDL_RendererFlip sdl_flip = flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    //Set rendering space and render to screen
    //SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), width, height };
    SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;

    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, 0.0, nullptr, sdl_flip);
}
