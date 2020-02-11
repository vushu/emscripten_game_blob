#pragma once

#include "components.hpp"
#include <map>
#include <entt/entt.hpp>
#include <vector>
#include "tilemap.hpp"
#include "Collision_corners.hpp"

class Collision_system {

    private:
        Collision_corners player_points;

    public:
        void update(entt::registry& registry, std::vector<std::vector<int>>& tilemap);
        void print_tile_info(Tilemap::Tile_info &tile_info);

};
