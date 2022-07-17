#include "game/battle/state.hpp"
#include <SDL2/SDL_timer.h>
#include <iostream>

using std::cout;
using std::endl;


void game::battle::game_over()
{
    player.hp = 0;
    cout << "Game over" << endl;
    load_battle();
}
