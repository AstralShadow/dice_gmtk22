#ifndef INCLUDE_PAWN_HPP
#define INCLUDE_PAWN_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

struct SDL_Texture;


namespace game::board
{
    struct Pawn
    {
        float progress = 0;
        int hp = 3;
        float regen_buffer = 0;
    };

    extern Pawn pawn;
    SDL_Texture* get_texture(Pawn const&);
    void render_pawn();
}

#endif // INCLUDE_PAWN_HPP
