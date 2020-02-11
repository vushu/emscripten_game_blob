#include "apple.hpp"

Apple::Apple(SDL_Renderer* renderer)
{
    Apple::renderer = renderer;
    clip.w = 32;
    clip.h = 32;
    clip.y = 0;
    texture = std::make_unique<Texture>(renderer, "resources/Items/Fruits/Apple.png");
}
Apple::~Apple()
{
    //std::cout << "Freed Apple" << std::endl;
}

void Apple::animate(int x, int y)
{

    int frame = (SDL_GetTicks() / delay_per_frame) % 17;
    clip.x = frame * 32;

    std::cout << frame << std::endl;
    texture->draw(x, y, &clip);


    if ((frame / 17) >= 17) {
        std::cout << "CYCLE ANIMATION" << std::endl;
        frame = 0;
    }
}
//}
//texture->set_alpha(127);
