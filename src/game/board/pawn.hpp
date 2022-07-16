#ifndef INCLUDE_PAWN_HPP
#define INCLUDE_PAWN_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

struct SDL_Texture;


namespace game::board
{
    struct Pawn
    {
        float progress = 0.87;
        int hp = 3;
    };

    extern Pawn player;
    SDL_Texture* get_texture(Pawn const&);
    void render_pawn();
}

#endif // INCLUDE_PAWN_HPP
