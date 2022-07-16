#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"

void game::board_on_motion(u32 x, u32 y)
{
    auto screen = board_camera.size;

    Point margin {
        game::board::map_size.x - screen.x,
        game::board::map_size.y - screen.y
    };

    FPoint target {
        margin.x * x * 1.0f / screen.x,
        margin.y * y * 1.0f / screen.y
    };

    board_camera.target_pos = target;
}

