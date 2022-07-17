#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/state.hpp"
#include "game/battle/render.hpp"
#include "game/battle/player.hpp"
#include "game/textures.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>
#include <cmath>

static auto& rnd = core::renderer;


void game::battle::render_hud()
{
    render_energy();
}

void game::battle::render_energy()
{
    auto full = texture(HUD_DICE);
    auto empty = texture(HUD_DICE_EMPTY);
    auto size = texture_size(HUD_DICE);
    auto step = size.x + 6;
    auto screen = camera.size;

    SDL_Rect dst{
        screen.x - 24 - size.x, 24,
        size.x, size.y
    };

    for(u8 i = 0; i < player.energy_limit; i++) {
        float filled = std::min(1.0f, player.energy - i);
        SDL_RenderCopy(rnd, empty, nullptr, &dst);

        if(filled > 0) {
            dst.h = size.y * filled;
            dst.y += size.y - dst.h;

            SDL_Rect src {
                0, size.x - dst.h,
                dst.w, dst.h
            };

            SDL_RenderCopy(rnd, full, &src, &dst);
        }

        dst.y = 24;
        dst.h = size.y;
        dst.x -= step;
    }

}

void game::battle::render_lifetime()
{

}
