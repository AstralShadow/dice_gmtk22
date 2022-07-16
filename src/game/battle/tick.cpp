#include "game/game.hpp"
#include "game/camera.hpp"


void game::battle::tick(u32 ms)
{
    camera.tick(ms);

}
