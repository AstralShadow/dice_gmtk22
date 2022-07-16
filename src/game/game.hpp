#ifndef INCLUDE_GAME_HPP
#define INCLUDE_GAME_HPP

#include "utils/types.hpp"

namespace game
{
    void init(int, char**);

    void tick(u32 ms);
    void menu_tick(u32);
    void board_tick(u32);
    void battle_tick(u32);

    void render();
    void menu_render();
    void board_render();
    void battle_render();

    template<typename T>
    extern void handle_event(T&);

    void board_on_motion(u32 x, u32 y);
}

#endif // INCLUDE_GAME_HPP
