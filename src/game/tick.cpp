#include "game/game.hpp"
#include "game/data.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::tick(u32 ms)
{
    switch(scene) {
    case SCENE_MENU:
        menu::tick(ms);
        break;

    case SCENE_BOARD:
        board::tick(ms);
        break;

    case SCENE_BATTLE:
        battle::tick(ms);
        break;
    }
}
