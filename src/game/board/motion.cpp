#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"
#include "game/board/pawn.hpp"
#include "game/board/path.hpp"
#include "game/textures.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::board::motion(u32 x, u32 y)
{
    auto screen = camera.size;

    Point margin {
        game::board::map_size.x - screen.x,
        game::board::map_size.y - screen.y
    };

    FPoint target {
        margin.x * x * 1.0f / screen.x,
        margin.y * y * 1.0f / screen.y
    };

    camera.target_pos = target;
}

