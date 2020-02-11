#pragma once
#include "animated_sprite.hpp"
#include "components.hpp"
#include "text.hpp"
#include "texture.hpp"
#include "tilemap.hpp"
#include <SDL2/SDL_render.h>
#include <entt/entt.hpp>
#include <iostream>
#include <map>
#include <vector>

class Render {
public:
    //Render();
    std::map<std::string, std::unique_ptr<Animated_sprite>> animated_sprites;
    std::map<std::string, std::unique_ptr<Text>> texts;
    std::unique_ptr<Texture> tiles;
    void update(std::uint64_t dt, entt::registry& registry, SDL_Renderer* renderer, SDL_Rect& camera, std::unique_ptr<Texture>& tiles, std::vector<std::vector<int>>& tilemap);
    void draw_tiles_level(SDL_Rect& camera, std::unique_ptr<Texture>& texture, std::vector<std::vector<int>>& tilemap);
};
