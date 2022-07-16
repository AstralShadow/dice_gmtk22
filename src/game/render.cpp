#include "game/game.hpp"
#include "game/data.hpp"
#include "core/core.hpp"
#include <iostream>

using core::renderer;
using std::cout;
using std::endl;


void game::render()
{
    switch(scene) {
    case SCENE_MENU:
        //cout << "Menu not implemented" << endl;
        break;

    case SCENE_BOARD:
        board_render();
        //cout << "Board not implemented" << endl;
        break;

    case SCENE_BATTLE:
        //cout << "Battle not implemented" << endl;
        break;
    }
}
