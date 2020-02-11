#include "render_system.hpp"
#include "tilemap.hpp"
#include <vector>

void Render::draw_tiles_level(SDL_Rect& camera, std::unique_ptr<Texture>& texture, std::vector<std::vector<int>>& tilemap)
{
    int tilesize = 16;
    float x, y;
    SDL_Rect clip;
    int rows = tilemap.size();
    int cols = tilemap[0].size();
    //std::cout << "rows" << std::endl;
    //std::cout << rows << std::endl;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            //std::cout << Tilemap::level1[i][j] << " ";

            if (tilemap[i][j] == 1) {
                //SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                //SDL_Rect fillRect = { j * tilesize - camera.x, i * tilesize - camera.y, tilesize, tilesize };
                clip = { 6 * 16, 0, 16, 16 };
                //SDL_RenderFillRect(renderer, &fillRect);
                texture.get()->draw(x, y, &clip);
            } else if (tilemap[i][j] == 2) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 7 * 16, 0, 16, 16 };
                texture.get()->draw(x, y, &clip);
            } else if (tilemap[i][j] == 3) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 8 * 16, 0, 16, 16 };
                texture.get()->draw(x, y, &clip);
            } else if (tilemap[i][j] == 4) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 6 * 16, 1 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);
            } else if (tilemap[i][j] == 5) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 7 * 16, 1 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);
            } else if (tilemap[i][j] == 6) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 8 * 16, 1 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);

            } else if (tilemap[i][j] == 7) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 6 * 16, 2 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);

            } else if (tilemap[i][j] == 8) {
                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 7 * 16, 2 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);

            } else if (tilemap[i][j] == 9) {

                x = j * tilesize - camera.x;
                y = i * tilesize - camera.y;
                clip = { 8 * 16, 2 * 16, 16, 16 };
                texture.get()->draw(x, y, &clip);
            }
        }
    }
}

void Render::update(std::uint64_t dt, entt::registry& registry, SDL_Renderer* renderer, SDL_Rect& camera, std::unique_ptr<Texture>& texture, std::vector<std::vector<int>>& tilemap)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    draw_tiles_level(camera, texture, tilemap);

    const auto& view = registry.view<Sprite, Position>();

    for (auto entity : view) {

        auto& sprite = view.get<Sprite>(entity);
        auto& anim_sprite = animated_sprites.at(sprite.name);
        auto& pos = view.get<Position>(entity);
        anim_sprite.get()->animate(pos.x - camera.x, pos.y - camera.y, 50, 32, 0, sprite.flip);
    }

    // drawing collision
    // for debugging
    if (false) {
        const auto& view2 = registry.view<Collision, Position>();
        for (auto& en : view2) {
            auto& pos2 = view2.get<Position>(en);
            auto& collision2 = view2.get<Collision>(en);
            SDL_Rect fillRect = { static_cast<int>(pos2.x + collision2.offset_x) - camera.x,
                static_cast<int>(pos2.y + collision2.offset_y) - camera.y,
                static_cast<int>(collision2.w),
                static_cast<int>(collision2.h) };
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
            SDL_RenderDrawRect(renderer, &fillRect);
        }
    }

    //const auto& view3 = registry.view<Debug_text, Position>();

    //for (auto& entity : view3) {
    //auto& text = view3.get<Debug_text>(entity);
    //auto& pos = view3.get<Position>(entity);
    //texts.at(text.text).get()->render(pos.x, pos.y);
    //}

    //for (auto& text : texts) {
    //text.second.get()->render(, float y)
    //}

    SDL_RenderPresent(renderer);
}
