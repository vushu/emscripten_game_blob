#include "texture.hpp"
#include "utils.hpp"

Texture::Texture(SDL_Renderer* renderer, std::string path)
{
    Texture::renderer = renderer;
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());

    if (!loaded_surface) {
        std::cout << "Failed to load texture" << std::endl;
        throw "failed to load file";
    }
}

Texture::~Texture()
{
    free();
}

void Texture::free()
{
    std::cout << "freed texture" << std::endl;
    SDL_DestroyTexture(texture);
}
