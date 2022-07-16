#ifndef INCLUDE_STATE_HPP
#define INCLUDE_STATE_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include "game/terrain.hpp"

namespace game::battle
{
    extern terrain_t terrain;

    [[maybe_unused]]
    const Point margin {30, 30};
}

#endif // INCLUDE_STATE_HPP
