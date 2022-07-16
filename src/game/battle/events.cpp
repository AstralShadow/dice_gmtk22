#include <SDL_events.h>
#include "game/game.hpp"
#include "game/battle/player.hpp"
#include "game/battle/render.hpp"
#include <cmath>


void game::battle::keyboard(SDL_KeyboardEvent&)
{

}

void game::battle::lclick(u32 x, u32 y)
{
    auto pos = localize({
        static_cast<float>(x),
        static_cast<float>(y)
    });

    auto p_size = texture_size(player);

    pos.x -= p_size.x / 2;
    pos.y -= p_size.y * 2 / 3;

    float angle = atan2(
        static_cast<int>(pos.y - player.pos.y),
        static_cast<int>(pos.x - player.pos.x)
    );

    player_rush(angle);
}

void game::battle::rclick(u32, u32)
{

}
