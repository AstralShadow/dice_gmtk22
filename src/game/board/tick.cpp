#include "game/game.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"

void game::board_tick(u32 ms)
{
    board_camera.tick(ms);
}
