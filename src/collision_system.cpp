#include "collision_system.hpp"
#include "components.hpp"
#include "tilemap.hpp"
#include <array>

static bool left_foot_on = false;
static bool right_foot_on = false;
static int tile_size = 16;
void Collision_system::print_tile_info(Tilemap::Tile_info& tile_info)
{
    std::cout << "========================" << std::endl;
    std::cout << "Tile INDEX:" << std::endl;
    std::cout << tile_info.i_x << std::endl;
    std::cout << tile_info.i_y << std::endl;
    std::cout << "Tile ID:" << std::endl;
    std::cout << tile_info.tile_id << std::endl;
    std::cout << "========================" << std::endl;
}

void Collision_system::update(entt::registry& registry, std::vector<std::vector<int>>& tilemap)
{
    float shrink = 4.9f; // shrink value to not collide on different tiles
    const auto& view = registry.view<Player, Collision, Position, Velocity>();
    //const auto& view2 = registry.view<Solid, Collision, Position>();
    for (const auto& entity : view) {
        auto& p_col = view.get<Collision>(entity);
        auto& p_pos = view.get<Position>(entity);
        auto& p_vel = view.get<Velocity>(entity);
        auto& player = view.get<Player>(entity);
        player_points.calc_corners(p_pos.x, p_pos.y, p_col.offset_x, p_col.offset_y, p_col.w, p_col.h);

        if (p_vel.dx <= 0) {
            // Why -2? watch
            // https://www.youtube.com/watch?v=oJvJZNyW_rw
            // javidx9
            //bot left
            // collides with tile_right
            SDL_Point point = Tilemap::get_index(player_points.bottom_left.x, player_points.bottom_left.y - shrink, tile_size);
            float p_left = p_pos.x + p_col.offset_x;
            //if (Tilemap::tile_exists(point)) {

            //auto point = player_points.get_index(float x, float y, int tile_size)
            auto tile_info = Tilemap::get_tile(tilemap, point, tile_size);

            //float p_left = p_pos.x + p_col.offset_x;

            // checking only on x axis
            if (tile_info.tile_id != 0 && player_points.bottom_left.x < tile_info.right) {
                p_vel.dx = 0;
                p_pos.x = tile_info.right - p_col.offset_x;
                //return;
            }

            // top left
            point = Tilemap::get_index(player_points.top_left.x, player_points.top_left.y + shrink, tile_size);
            //if (Tilemap::tile_exists(point)) {

            tile_info = Tilemap::get_tile(tilemap, point, tile_size);

            // checking only on x axis
            if (tile_info.tile_id != 0 && player_points.top_left.x < tile_info.right) {
                //print_tile_info(tile_info);
                p_vel.dx = 0;
                p_pos.x = tile_info.right - p_col.offset_x;
            }
            //}
        } else if (p_vel.dx > 0) {

            //bot right
            SDL_Point point = Tilemap::get_index(player_points.bottom_right.x, player_points.bottom_right.y - shrink, tile_size);
            //float p_x = p_pos.x + p_col.offset_x + p_col.w;
            //float p_y = p_pos.y + p_col.offset_y + p_col.h - shrink;
            // collides with tile_right
            //if (Tilemap::tile_exists(point)) {
            auto tile_info = Tilemap::get_tile(tilemap, point, tile_size);

            float p_right = p_pos.x + p_col.offset_x + p_col.w;

            // checking only on x axis
            if (tile_info.tile_id != 0 && player_points.bottom_right.x > tile_info.left) {
                //std::cout << "bot left" << std::endl;
                player.on_ground = true;
                p_vel.dx = 0;
                p_pos.x = tile_info.left - (p_col.offset_x + p_col.w);
                //return;
            } else {
                player.on_ground = false;
            }
            //}

            // top right
            //p_x = p_pos.x + p_col.offset_x + p_col.w;
            point = Tilemap::get_index(player_points.top_right.x, player_points.top_right.y + shrink, tile_size);
            //if (Tilemap::tile_exists(point)) {

            tile_info = Tilemap::get_tile(tilemap, point, tile_size);

            // checking only on x axis
            if (tile_info.tile_id != 0 && player_points.top_right.x > tile_info.left) {
                player.on_ground = true;
                p_vel.dx = 0;
                p_pos.x = tile_info.left - (p_col.offset_x + p_col.w);
            } else {
                player.on_ground = false;
            }
        }

        // Y_AXIS hitting down
        if (p_vel.dy > 0) {
            //bot_left with a bit offset to the right
            bool left_foot_on = false;
            bool right_foot_on = false;

            SDL_Point point = Tilemap::get_index(player_points.bottom_left.x + shrink, player_points.bottom_left.y, tile_size);
            //if (Tilemap::tile_exists(point)) {
            auto tile_info = Tilemap::get_tile(tilemap, point, tile_size);
            float p_bot = p_pos.y + p_col.offset_y + p_col.h;

            // checking y - axis
            if (tile_info.tile_id != 0 && player_points.bottom_left.y > tile_info.top) {
                //std::cout << "p_bot hit tile.top" << std::endl;
                //print_tile_info(tile_info);
                p_vel.dy = 0;
                left_foot_on = true;
                p_pos.y = tile_info.top - (p_col.offset_y + p_col.h) + 1;
            } else {
                left_foot_on = false;
            }
            //}

            // bot right;
            point = Tilemap::get_index(player_points.bottom_right.x - shrink, player_points.bottom_right.y, tile_size);
            //if (Tilemap::tile_exists(point)) {

            tile_info = Tilemap::get_tile(tilemap, point, tile_size);

            // checking y - axis
            if (tile_info.tile_id != 0 && player_points.bottom_right.y > tile_info.top) {
                //std::cout << "p_bot hit tile.top" << std::endl;
                //print_tile_info(tile_info);
                p_vel.dy = 0;
                right_foot_on = true;
                p_pos.y = tile_info.top - (p_col.offset_y + p_col.h) + 1;
            } else {
                right_foot_on = false;
            }

            player.on_ground = left_foot_on || right_foot_on;
            //}
        } else if (p_vel.dy <= 0) {

            SDL_Point point = Tilemap::get_index(player_points.top_left.x + shrink, player_points.top_left.y, tile_size);
            //if (Tilemap::tile_exists(point)) {

            auto tile_info = Tilemap::get_tile(tilemap, point, tile_size);
            //float p_top = p_pos.y + p_col.offset_y;

            if (tile_info.tile_id != 0 && player_points.top_left.y < tile_info.bottom) {
                //std::cout << "hit bot tile" << std::endl;
                //print_tile_info(tile_info);
                p_vel.dy = 0;
                p_pos.y = tile_info.bottom + p_col.offset_y;
            }
            //}

            //p_x = p_pos.x + p_col.offset_x + p_col.w - shrink;
            //p_y = p_pos.y + p_col.offset_y;
            //top right
            point = Tilemap::get_index(player_points.top_right.x - shrink, player_points.top_right.y, tile_size);
            //if (Tilemap::tile_exists(point)) {

            tile_info = Tilemap::get_tile(tilemap, point, tile_size);
            //p_top = p_pos.y + p_col.offset_y;

            if (tile_info.tile_id != 0 && player_points.top_right.y < tile_info.bottom) {
                p_vel.dy = 0;
                p_pos.y = tile_info.bottom + p_col.offset_y;
            }
            //}
        }
    }
}
