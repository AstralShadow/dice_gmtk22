#include "game/board/pawn.hpp"
#include "game/textures.hpp"

using game::board::Pawn;
using game::texture;

Pawn game::board::pawn;

SDL_Texture* game::board::get_texture(Pawn const& pawn)
{
    switch(pawn.hp) {
    case 3:
        return texture(TX_PAWN "lime.png");
    case 2:
        return texture(TX_PAWN "yellow.png");
    case 1:
        return texture(TX_PAWN "orange.png");
    case 0:
        return texture(TX_PAWN "red.png");
    }

    return nullptr;
}
