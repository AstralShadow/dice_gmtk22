#ifndef INCLUDE_TICK_HPP
#define INCLUDE_TICK_HPP

#include "utils/types.hpp"


namespace game::battle
{
    struct Crystal;
    struct Bullet;

    void tick(u32);
    void tick_player(u32);
    void tick_player_rush(u32);
    void tick_crystal(Crystal&, u32);
    void tick_bullet(Bullet&, u32);
    void player_collisions(u32);
    void bullet_collisions(u32);
}

#endif // INCLUDE_TICK_HPP
