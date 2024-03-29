#include "game/game.hpp"
#include "game/camera.hpp"
#include "game/textures.hpp"
#include "game/board/private.hpp"
#include "core/core.hpp"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace board = game::board;
using std::cout;
using std::endl;

Point board::map_size {0, 0};


void board::render_background()
{
    auto rnd = core::renderer;
    auto screen = camera.size;
    board::calculate_map_size();

    SDL_Rect src {
        static_cast<int>(camera.pos.x),
        static_cast<int>(camera.pos.y),
        screen.x,
        screen.y
    };

    SDL_RenderCopy(
        rnd,
        board::map_cache(),
        &src,
        nullptr
    );
}

static bool can_render_to_texture()
{
    SDL_RendererInfo info;
    SDL_GetRendererInfo(core::renderer, &info);
    return info.flags & SDL_RENDERER_TARGETTEXTURE;
}

SDL_Texture* game::board::map_cache()
{
    static bool available = can_render_to_texture();
    if(!available)
        return game::texture(TEXTURE_MAP);

    static SDL_Texture* map = nullptr;
    static Point size{0, 0};

    calculate_map_size();
    if(size != map_size) {
        auto original = game::texture(TEXTURE_MAP);
        auto rnd = core::renderer;
        if(map)
            SDL_DestroyTexture(map);

        map = SDL_CreateTexture(
            rnd,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            map_size.x,
            map_size.y
        );

        SDL_SetRenderTarget(rnd, map);
        SDL_RenderCopy(rnd, original, nullptr, nullptr);
        SDL_SetRenderTarget(rnd, nullptr);

        size = map_size;
    }

    return map;

}


void game::board::calculate_map_size()
{
    static Point screen_cache {0, 0};
    auto screen = camera.size;
    if(screen_cache == screen)
        return;
    screen_cache = screen;

    screen.x += camera_margin.x;
    screen.y += camera_margin.y;
    auto original = game::texture_size(TEXTURE_MAP);
    map_size = cover(original, screen);
    camera.scale =
        static_cast<float>(map_size.x) / original.x;
}

Point game::board::cover(Point source, Point target)
{
    float ratio = std::max(
        static_cast<float>(target.x) / source.x,
        static_cast<float>(target.y) / source.y
    );

    return {
        static_cast<int>(source.x * ratio),
        static_cast<int>(source.y * ratio)
    };
}
