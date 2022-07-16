#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/tick.hpp"
#include "game/battle/player.hpp"


void game::battle::tick(u32 ms)
{
    camera.tick(ms);
    tick_player(ms);
}


