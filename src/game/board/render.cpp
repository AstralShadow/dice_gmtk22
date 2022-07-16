#include "game/game.hpp"
#include "core/core.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"
#include "game/board/pawn.hpp"
#include "game/board/path.hpp"
#include "game/textures.hpp"
#include <SDL2/SDL_render.h>


void game::board_render()
{
    board::render_background();
    board::render_pawn();
}

void game::board::render_pawn()
{
    auto rnd = core::renderer;
    auto size = game::texture_size(TX_PAWN "lime.png");
    auto pos = path_pos(player.progress);
    auto offset = game::board_camera.pos;
    auto scale = game::board_camera.scale;

    SDL_Rect out {
        static_cast<int>(pos.x * scale - offset.x),
        static_cast<int>(pos.y * scale - offset.y),
        static_cast<int>(size.x),
        static_cast<int>(size.y)
    };
    out.x -= out.w / 2;
    out.y -= out.h;

    auto tx = get_texture(player);
    SDL_RenderCopy(rnd, tx, nullptr, &out);
}
