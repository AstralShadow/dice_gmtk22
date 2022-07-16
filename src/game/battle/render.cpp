#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/state.hpp"
#include "game/battle/render.hpp"
#include "game/battle/player.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>
#include <cmath>

static auto& rnd = core::renderer;


void game::battle::render()
{
    render_background();
    render_player();

    render_hud();
}

// TODO: entities disappearing when leaving fullscreen
// note: they do appear on mouse motion

void game::battle::render_player()
{
    auto tx = texture(player);
    auto size = texture_size(player);

    SDL_Rect area {
        static_cast<int>(player.pos.x),
        static_cast<int>(player.pos.y),
        size.x, size.y
    };

    render_entity(tx, area);
}

void game::battle::
render_entity(SDL_Texture* tx, SDL_Rect const& area)
{
    auto screen = camera.size;
    auto arena = texture_size(terrain);

    SDL_Rect out {
        static_cast<int>(area.x - camera.pos.x),
        static_cast<int>(area.y - camera.pos.y),
        area.w, area.h
    };

    if(screen.x > arena.x)
        out.x = area.x + (screen.x - arena.x) / 2;
    if(screen.y > arena.y)
        out.y = area.y + (screen.y - arena.y) / 2;

    SDL_RenderCopy(rnd, tx, nullptr, &out);
}

FPoint game::battle::localize(FPoint in)
{
    auto screen = camera.size;
    auto arena = texture_size(terrain);

    FPoint out {
        in.x + camera.pos.x,
        in.y + camera.pos.y,
    };

    if(screen.x > arena.x)
        out.x = in.x - (screen.x - arena.x) / 2;
    if(screen.y > arena.y)
        out.y = in.y - (screen.y - arena.y) / 2;

    return out;
}
