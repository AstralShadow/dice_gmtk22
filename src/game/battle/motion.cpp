#include "game/battle/state.hpp"
#include "game/game.hpp"
#include "game/camera.hpp"

void game::battle::motion(u32 x, u32 y)
{
    auto screen = camera.size;
    auto size = texture_size(terrain);

    Point margin {
        size.x - screen.x,
        size.y - screen.y
    };

    FPoint target {
        margin.x * x * 1.0f / screen.x,
        margin.y * y * 1.0f / screen.y
    };

    camera.target_pos = target;
}

