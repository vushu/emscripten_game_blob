#include "text.hpp"

Text::~Text()
{
    SDL_DestroyTexture(texture);
}

Text::Text(SDL_Renderer* renderer, std::string text, int size)
{
    //font = TTF_OpenFont("resources/ttf/LANENAR_.ttf", size);
    //Text::renderer = renderer;
    //SDL_Color text_color = { 0, 0, 0 };
    //SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
    //if (!text_surface) {
        //std::cout << "Failed to render surface for text" << std::endl;
        //throw std::runtime_error("failed to create text");
    //}

    //texture = SDL_CreateTextureFromSurface(renderer, text_surface);

    //if (!texture) {
        //std::cout << "Failed to render surface for text" << std::endl;
        //throw std::runtime_error("failed to create texture");
    //}

    //width = text_surface->w;
    //height = text_surface->h;

    //SDL_FreeSurface(text_surface);
    //TTF_CloseFont(font);


}

void Text::render(float x, float y)
{
    SDL_Rect renderQuad = { static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height) };
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);

}
