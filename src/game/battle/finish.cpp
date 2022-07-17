#include "game/battle/state.hpp"
#include "game/data.hpp"
#include "game/story/scenes.hpp"
#include <SDL2/SDL_timer.h>
#include <iostream>

using std::cout;
using std::endl;


void game::battle::game_over()
{
    player.hp = 0;
    load_battle();
    story::single(story::STORY_GAME_OVER, SCENE_BATTLE);
}

void game::battle::win_round()
{
    unload_battle();
}
