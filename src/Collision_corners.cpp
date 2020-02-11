#include "Collision_corners.hpp"

void Collision_corners::calc_corners(float pos_x, float pos_y, float offset_x, float offset_y, float w, float h)
{
    top_left.x = pos_x + offset_x;
    top_left.y = pos_y + offset_y;

    top_right.x = pos_x + offset_x + w;
    top_right.y = pos_y + offset_y;

    bottom_left.x = pos_x + offset_x;
    bottom_left.y = pos_y + offset_y + h;

    bottom_right.x = pos_x + offset_x + w;
    bottom_right.y = pos_y + offset_y + h;
}

