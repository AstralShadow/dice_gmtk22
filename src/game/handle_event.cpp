#include "core/core.hpp"
#include "game/game.hpp"
#include "game/data.hpp"
#include <SDL2/SDL_events.h>


template<>
void game::handle_event(SDL_KeyboardEvent& ev)
{
    if(ev.keysym.sym == SDLK_q)
        core::stop();
}


template<>
void game::handle_event(SDL_MouseButtonEvent&)
{

}

template<>
void game::handle_event(SDL_MouseMotionEvent& ev)
{
    switch(scene) {
        case SCENE_BOARD:
            board_on_motion(ev.x, ev.y);
            break;
        default:
            break;
    }
}

template<>
void game::handle_event(SDL_MouseWheelEvent&)
{

}


template<>
void game::handle_event(SDL_DropEvent&)
{

}
