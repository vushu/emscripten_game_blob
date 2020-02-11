#pragma once
#include "animated_sprite.hpp"
#include "components.hpp"
#include "text.hpp"
#include <entt/entt.hpp>
#include <map>
#include <memory>

enum Fruit {
    APPLE,
    KIWI,
    MELON,
    ORANGE,
    BANANAS,
    CHERRIES,
    PINEAPPLE,
    STRAWBERRY
};
namespace Factories {

void create_fruit(std::map<std::string, std::unique_ptr<Animated_sprite>>& animated_sprites, entt::registry& registry, SDL_Renderer* renderer, Fruit type, float x, float y);
void create_player(std::map<std::string, std::unique_ptr<Animated_sprite>>& animated_sprites, entt::registry& registry, SDL_Renderer* renderer, float x, float y);
void create_platform(entt::registry& registry, float x, float y, float w, float h);
void create_text(entt::registry& registry, SDL_Renderer* renderer, std::map<std::string, std::unique_ptr<Text>>& texts, std::string text, float x, float y);
//void create_camera(entt::registry& registry);

}
