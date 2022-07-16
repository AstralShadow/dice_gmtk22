#include "core/core.hpp"
#include "game/game.hpp"
#include "game/data.hpp"
#include <SDL2/SDL_events.h>


template<>
void game::handle_event(SDL_KeyboardEvent& ev)
{
    if(ev.keysym.sym == SDLK_q)
        core::stop();

    switch(scene) {
        case SCENE_BATTLE:
            battle::keyboard(ev);
            break;
        default:
            break;
    }
}


template<>
void game::handle_event(SDL_MouseButtonEvent& ev)
{
    if(ev.state == SDL_RELEASED)
        return;

    switch(scene) {
    case SCENE_BATTLE:
        if(ev.button == SDL_BUTTON_LEFT)
            battle::lclick(ev.x, ev.y);
        if(ev.button == SDL_BUTTON_RIGHT)
            battle::rclick(ev.x, ev.y);
        break;
    default:
        break;
    }
}

template<>
void game::handle_event(SDL_MouseMotionEvent& ev)
{
    switch(scene) {
    case SCENE_BOARD:
        board::motion(ev.x, ev.y);
        break;
    case SCENE_BATTLE:
        battle::motion(ev.x, ev.y);
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
