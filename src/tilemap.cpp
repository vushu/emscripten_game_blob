#include "tilemap.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <math.h>

SDL_Point Tilemap::get_index(float x, float y, int tile_size)
{
    int p_x = (int)(x / tile_size);
    int p_y = (int)(y / tile_size);
    return SDL_Point{ p_x, p_y };
}

Tilemap::Tile_info Tilemap::get_tile(std::vector<std::vector<int>>& tilemap, SDL_Point& point, int tile_size)
{
    Tilemap::Tile_info tile_info;
    int i_x = point.x;
    int i_y = point.y;
    tile_info.i_x = i_x;
    tile_info.i_y = i_y;
    int rows = tilemap.size();
    int cols = tilemap[0].size();
    tile_info.tile_id = 0;
    //std::cout << rows << std::endl;
    //std::cout << cols << std::endl;
    // y coordinates looks at rows!
    // x coordinates looks at cols!
    if (i_x < 0 || i_x >= cols || i_y < 0 || i_y >= rows) {

        //std::cout << "out of bounds " << std::endl;
        tile_info.tile_id = 0;
    } else {
        //std::cout << "Tile ID" << std::endl;
        tile_info.tile_id = tilemap.at(i_y).at(i_x);
        //std::cout << tile_info.tile_id << std::endl;
        //std::cout << i_y << std::endl;
        //std::cout << i_x << std::endl;
    }

    tile_info.bottom = std::abs(i_y * tile_size + tile_size);
    tile_info.top = std::abs(i_y * tile_size);
    tile_info.left = std::abs(i_x * tile_size);
    tile_info.right = std::abs(i_x * tile_size + tile_size);
    return tile_info;
}

std::vector<std::vector<int>> Tilemap::generate_tilemap()
{
    int m = 10, n = 12000;
    std::vector<std::vector<int>> a;
    //Grow rows by m
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        //Grow Columns by n
        a[i].resize(n);
    }

    for (auto i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) { //modify matrix
            a[i][j] = 0;
        }
    }

    for (auto i = 9; i < m; ++i) {
        for (int j = 0; j < n; ++j) { //modify matrix
            //int randnum = std::rand() % 1 + 1 == 1 ? std::rand() % 1 + 1 : 0;
            int randnum = std::rand() % 3;
            a[i][j] = randnum;
        }
    }

    //for (auto i = 0; i < m; ++i) {
        //for (int j = 0; j < n; ++j) { //modify matrix
            //std::cout << a[i][j];
        //}
        //std::cout << std::endl;
    //}

    return a;
}
