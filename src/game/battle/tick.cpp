#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/tick.hpp"
#include "game/battle/state.hpp"
#include "game/battle/player.hpp"
#include "game/battle/crystal.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::battle::tick(u32 ms)
{
    base_attack_timer += ms;

    lifetime -= ms / 1000.0f;
    if(lifetime < 0) {
        win_round();
        return;
    }

    camera.tick(ms);
    tick_player(ms);

    for(auto& crystal : crystals)
        tick_crystal(crystal, ms);

    for(auto& bullet : bullets)
        tick_bullet(bullet, ms);

    bullet_collisions(ms);
    player_collisions(ms);
}


