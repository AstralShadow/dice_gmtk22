#include "game/game.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"
#include "game/board/pawn.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::board::tick(u32 ms)
{
    camera.tick(ms);
    pawn.progress += 0.001; 
    if(pawn.progress > 1)
        pawn.progress = 0.7;
}
