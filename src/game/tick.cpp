#include "game/game.hpp"
#include "game/data.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace game {
    void menu_tick(u32);
    void board_tick(u32);
    void battle_tick(u32);
}


void game::tick(u32 ms)
{
    switch(scene) {
    case SCENE_MENU:
        //menu_tick(ms);
        cout << "Menu not implemented" << endl;
        break;

    case SCENE_BOARD:
        board_tick(ms);
        cout << "Board not implemented" << endl;
        break;

    case SCENE_BATTLE:
        //battle_tick(ms);
        cout << "Battle not implemented" << endl;
        break;
    }
}
