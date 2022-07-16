#ifndef INCLUDE_TICK_HPP
#define INCLUDE_TICK_HPP

#include "utils/types.hpp"


namespace game::battle
{
    void tick(u32);
    void tick_player(u32);
    void tick_player_rush(u32);
}

#endif // INCLUDE_TICK_HPP
