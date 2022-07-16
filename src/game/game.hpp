#ifndef INCLUDE_GAME_HPP
#define INCLUDE_GAME_HPP

#include "utils/types.hpp"

namespace game
{
    void init(int, char**);

    void tick(u32 ms);

    void render();

    namespace menu {
        void tick(u32);
        void render();
    }

    namespace board {
        void tick(u32);
        void render();
        void motion(u32 x, u32 y);
    }

    namespace battle {
        void tick(u32);
        void render();
        void motion(u32 x, u32 y);
    }

    template<typename T>
    extern void handle_event(T&);

}

#endif // INCLUDE_GAME_HPP
