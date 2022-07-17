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
    render_lifetime();
    render_active_skills();
}

void game::battle::render_energy()
{
    auto full = texture(HUD_DICE);
    auto empty = texture(HUD_DICE_EMPTY);
    auto size = texture_size(HUD_DICE);
    auto step = size.x + 6;
    auto screen = camera.size;

    SDL_Rect dst {
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
    auto full = texture(HUD_PROGRESS_FULL);
    auto empty = texture(HUD_PROGRESS_EMPTY);
    auto size = texture_size(HUD_PROGRESS_FULL);

    SDL_Rect dst {
        24, 24,
        size.x, size.y
    };

    SDL_RenderCopy(rnd, empty, nullptr, &dst);

    float filled = lifetime / max_lifetime;

    SDL_Rect src {
        0, 0,
        static_cast<int>(size.x * filled),
        size.y
    };

    dst.w = src.w;

    SDL_RenderCopy(rnd, full, &src, &dst);

}

void game::battle::render_active_skills()
{
    SDL_Texture* tx = nullptr;
    if(player.shield > 0)
        tx = texture(TX_HUD "shield.png");
    if(player.heal_cooldown > 0)
        tx = texture(TX_HUD "heal.png");
    if(player.r_time > 0)
        tx = texture(TX_HUD "speed.png");
    if(player.backfire_cooldown > 0)
        tx = texture(TX_HUD "add_evil_live.png");
    if(player.slow_motion > 0)
        tx = texture(TX_HUD "slowmo.png");
    if(player.time_halt > 0)
        tx = texture(TX_HUD "freeze.png");
    if(tx == nullptr)
        return;

    auto size = texture_size(TX_HUD "heal.png");

    auto screen = camera.size;

    SDL_Rect dst {
        screen.x / 2 - size.x / 2,
        screen.y - size.y - 24,
        size.x,
        size.y
    };

    SDL_RenderCopy(rnd, tx, nullptr, &dst);
}
