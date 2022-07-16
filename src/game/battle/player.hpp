#ifndef INCLUDE_PLAYER_HPP
#define INCLUDE_PLAYER_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

struct SDL_Texture;

namespace game::battle
{
    struct Player
    {
        Point pos {0, 0};
        int hp = 3;
    };
    extern Player player;

}

namespace game
{
    SDL_Texture* texture(battle::Player const&);
    Point texture_size(battle::Player const&);
}

#endif // INCLUDE_PLAYER_HPP
