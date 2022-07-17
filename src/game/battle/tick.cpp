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

    u32 enemy_ms = ms;
    if(player.time_halt > 0)
        enemy_ms = 0;
    if(player.slow_motion > 0)
        enemy_ms = ms / 2;

    if(enemy_ms > 0)
    for(auto& crystal : crystals)
        tick_crystal(crystal, enemy_ms);

    if(enemy_ms > 0)
    for(auto& bullet : bullets)
        tick_bullet(bullet, enemy_ms);

    bullet_collisions(ms);
    if(player.shield <= 0)
        player_collisions(ms);
}


