#include "game/game.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"
#include "core/core.hpp"
#include <iostream>
#include <array>
#include <SDL2/SDL_render.h>

using core::renderer;
using std::cout;
using std::endl;


void game::render()
{
    cameras_to_screen_size();

    switch(scene) {
    case SCENE_MENU:
        menu_render();
        break;

    case SCENE_BOARD:
        board_render();
        break;

    case SCENE_BATTLE:
        //cout << "Battle not implemented" << endl;
        break;
    }

    SDL_RenderPresent(core::renderer);
}
