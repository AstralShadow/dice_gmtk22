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
    SDL_RenderClear(core::renderer);

    cameras_to_screen_size();

    switch(scene) {
    case SCENE_MENU:
        menu::render();
        break;

    case SCENE_BOARD:
        board::render();
        break;

    case SCENE_BATTLE:
        battle::render();
        break;
    }

    SDL_RenderPresent(core::renderer);
}
