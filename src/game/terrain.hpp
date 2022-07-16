#ifndef INCLUDE_TERRAIN_HPP
#define INCLUDE_TERRAIN_HPP

#include "utils/point.hpp"

struct SDL_Texture;

namespace game
{
    enum terrain_t
    {
        FOREST,
        MEADOW,
        BEACH
    };

    SDL_Texture* texture(terrain_t);
    Point texture_size(terrain_t);
}

#endif // INCLUDE_TERRAIN_HPP
