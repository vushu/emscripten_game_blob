#include "factories.hpp"

void Factories::create_fruit(std::map<std::string, std::unique_ptr<Animated_sprite>>& animated_sprites, entt::registry& registry, SDL_Renderer* renderer, Fruit type, float x, float y)
{
    entt::entity entity = registry.create();
    std::unique_ptr<Animated_sprite> sprite;
    switch (type) {
    case APPLE:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Apple.png", 17, 32.0f, 32.0f);
        break;
    case KIWI:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Kiwi.png", 17, 32.0f, 32.0f);
        break;
    case MELON:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Melon.png", 17, 32.0f, 32.0f);
        break;
    case ORANGE:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Orange.png", 17, 32.0f, 32.0f);
        break;
    case BANANAS:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Bananas.png", 17, 32.0f, 32.0f);
        break;
    case CHERRIES:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Cherries.png", 17, 32.0f, 32.0f);
        break;
    case PINEAPPLE:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Pineapple.png", 17, 32.0f, 32.0f);
        break;
    case STRAWBERRY:
        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Strawberry.png", 17, 32.0f, 32.0f);
        break;
    default:

        sprite = std::make_unique<Animated_sprite>(renderer, "resources/Items/Fruits/Apple.png", 17, 32.0f, 32.0f);
    }
    animated_sprites.insert(std::make_pair(std::to_string(type), std::move(sprite)));

    registry.assign<Sprite>(entity, std::to_string(type));
    registry.assign<Position>(entity, x, y);
    registry.assign<Collision>(entity, 32.0f, 32.0f, 0.0f);
    registry.assign<Velocity>(entity, 10.0f, 0.0f);
    registry.assign<Consumable>(entity);
}

void Factories::create_player(std::map<std::string, std::unique_ptr<Animated_sprite>>& animated_sprites, entt::registry& registry, SDL_Renderer* renderer, float x, float y)
{
    entt::entity entity = registry.create();
    std::unique_ptr<Animated_sprite> sprite;

    sprite = std::make_unique<Animated_sprite>(renderer, "resources/Players/PinkMan/Idle (32x32).png", 11, 32, 32);
    animated_sprites.insert(std::make_pair("idle", std::move(sprite)));

    sprite = std::make_unique<Animated_sprite>(renderer, "resources/Players/PinkMan/Run (32x32).png", 12, 32, 32);
    animated_sprites.insert(std::make_pair("run", std::move(sprite)));

    sprite = std::make_unique<Animated_sprite>(renderer, "resources/Players/PinkMan/Jump (32x32).png", 1, 32, 32);
    animated_sprites.insert(std::make_pair("jump", std::move(sprite)));

    registry.assign<Player>(entity);
    registry.assign<Sprite>(entity, "idle");
    registry.assign<Position>(entity, x, y);
    registry.assign<Collision>(entity, 21.0f, 25.0f, 5.0f, 7.0f);
    registry.assign<Velocity>(entity, 0.0f, 0.0f);
}

//void Factories::create_camera(entt::entity& registry)
//{
    //auto entity = registry.create();
    //registry.assign<Camera>(entity, 0.0f, 0.0f);
//}

void Factories::create_platform(entt::registry& registry, float x, float y, float w, float h)
{
    entt::entity entity = registry.create();
    registry.assign<Solid>(entity);
    registry.assign<Position>(entity, x, y);
    registry.assign<Collision>(entity, w, h);
}

void Factories::create_text(entt::registry& registry, SDL_Renderer* renderer, std::map<std::string, std::unique_ptr<Text>>& texts, std::string text, float x, float y)
{
    entt::entity entity = registry.create();
    texts.insert(std::make_pair(text, std::make_unique<Text>(renderer, text, 20)));
    registry.assign<Debug_text>(entity, text);
    registry.assign<Position>(entity, x, y);
}
