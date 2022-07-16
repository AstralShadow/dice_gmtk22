#ifndef INCLUDE_PLAYER_HPP
#define INCLUDE_PLAYER_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

struct SDL_Texture;

namespace game::battle
{
    struct Player
    {
        FPoint pos;
        int hp;

        float speed = 300; // px/s

        /* Energy */
        float energy = 3;
        float energy_limit = 3;
        float recharge_rate = 0.2; // en/s

        /* Rushing */
        float r_time = 0; // [0, 0.2] seconds remaining
        float r_duration = 0.1;
        float r_speed = 2000; // px/s
        float r_direction = 0;
    };

    extern Player player;

    void player_rush(float direction);
}

namespace game
{
    SDL_Texture* texture(battle::Player const&);
    Point texture_size(battle::Player const&);
}

#endif // INCLUDE_PLAYER_HPP
