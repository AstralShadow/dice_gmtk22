#ifndef INCLUDE_STATE_HPP
#define INCLUDE_STATE_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include "game/terrain.hpp"
#include "game/battle/player.hpp"
#include "game/battle/crystal.hpp"

struct SDL_Texture;

namespace game::battle
{
    [[maybe_unused]]
    const Point margin {30, 30};

    extern terrain_t terrain;
    extern SDL_Texture* background;

    extern float lifetime; // level timer
    [[maybe_unused]]
    const float max_lifetime = 15.0f;
    extern float difficulty; // increase

    void load_battle();
    void unload_battle();

    void game_over();
    void win_round();
}

#endif // INCLUDE_STATE_HPP
