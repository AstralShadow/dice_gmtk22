#ifndef INCLUDE_GAME_HPP
#define INCLUDE_GAME_HPP

#include "utils/types.hpp"

struct SDL_KeyboardEvent;

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
        void keyboard(SDL_KeyboardEvent&);
        void rclick(u32 x, u32 y);
        void lclick(u32 x, u32 y);
    }

    namespace story {
        void tick(u32);
        void render();
        void click();
    }


    template<typename T>
    extern void handle_event(T&);

}

#endif // INCLUDE_GAME_HPP
