#include "game/battle/render.hpp"
#include "game/battle/state.hpp"
#include "game/camera.hpp"
#include "game/game.hpp"
#include "core/core.hpp"
#include <cmath>
#include <SDL2/SDL_render.h>

static auto& rnd = core::renderer;


void game::battle::render_background()
{
    auto screen = camera.size;
    auto size = texture_size(terrain);

    int cam_x = static_cast<int>(camera.pos.x);
    int cam_y = static_cast<int>(camera.pos.y);

    SDL_Rect src {
        std::min(std::max(0, size.x - screen.x), cam_x),
        std::min(std::max(0, size.y - screen.y), cam_y),
        std::min(screen.x, size.x),
        std::min(screen.y, size.y)
    };

    SDL_Rect dst {
        std::max(0, (screen.x - size.x) / 2),
        std::max(0, (screen.y - size.y) / 2),
        std::min(screen.x, size.x),
        std::min(screen.y, size.y)
    };

    SDL_RenderCopy(rnd, background, &src, &dst);
}
