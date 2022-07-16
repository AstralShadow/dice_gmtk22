#ifndef INCLUDE_PLAYER_HPP
#define INCLUDE_PLAYER_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

struct SDL_Texture;

namespace game::battle
{
    struct Player
    {
        Point pos;
        int hp = 3;
    };
    extern Player player;

    SDL_Texture* player_texture();
}

#endif // INCLUDE_PLAYER_HPP
