#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/battle/state.hpp"
#include "game/battle/render.hpp"
#include "game/battle/player.hpp"
#include "game/battle/crystal.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_render.h>
#include <cmath>

static auto& rnd = core::renderer;


void game::battle::render()
{
    render_background();
    render_player();

    for(auto& bullet : bullets)
        render_bullet(bullet);
    for(auto& crystal : crystals)
        render_crystal(crystal);

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

    render_entity(tx, nullptr, &area);
}

void game::battle::render_crystal(Crystal const& obj)
{
    auto tx = texture(obj);
    SDL_Rect src = get_frame(obj);

    SDL_Rect dst {
        static_cast<int>(obj.pos.x),
        static_cast<int>(obj.pos.y),
        src.w, src.h
    };

    render_entity(tx, &src, &dst);
}

void game::battle::render_bullet(Bullet const& obj)
{
    auto tx = texture(obj);
    SDL_Rect src = get_frame(obj);

    SDL_Rect dst {
        static_cast<int>(obj.pos.x),
        static_cast<int>(obj.pos.y),
        src.w, src.h
    };

    render_entity(tx, &src, &dst);
}


void game::battle::render_entity(SDL_Texture* tx,
                                 SDL_Rect const* src,
                                 SDL_Rect const* dst)
{
    auto screen = camera.size;
    auto arena = texture_size(terrain);

    SDL_Rect out {
        static_cast<int>(dst->x - camera.pos.x),
        static_cast<int>(dst->y - camera.pos.y),
        dst->w, dst->h
    };

    if(screen.x > arena.x)
        out.x = dst->x + (screen.x - arena.x) / 2;
    if(screen.y > arena.y)
        out.y = dst->y + (screen.y - arena.y) / 2;

    SDL_RenderCopy(rnd, tx, src, &out);
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
