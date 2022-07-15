#ifndef INCLUDE_GAME_HPP
#define INCLUDE_GAME_HPP

#include "utils/types.hpp"


namespace game
{
    void init(int, char**);

    void tick();
    void render();

    template<typename T>
    extern void handle_event(T&);
}

#endif // INCLUDE_GAME_HPP
