#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/tick.hpp"
#include "game/battle/player.hpp"
#include "game/battle/crystal.hpp"


void game::battle::tick(u32 ms)
{
    camera.tick(ms);
    tick_player(ms);

    for(auto& crystal : crystals)
        tick_crystal(crystal, ms);

    for(auto& bullet : bullets)
        tick_bullet(bullet, ms);

    player_collisions(ms);
}


