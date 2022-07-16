#include "game/game.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"
#include "game/board/pawn.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::board_tick(u32 ms)
{
    board_camera.tick(ms);
    //board::player.progress += 0.001; 
    //if(board::player.progress > 1)
    //    board::player.progress = 0.7;
    cout << board::player.progress << endl;
}
