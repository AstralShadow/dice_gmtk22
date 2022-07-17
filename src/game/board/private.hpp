#ifndef INCLUDE_PRIVATE_BOARD_HPP
#define INCLUDE_PRIVATE_BOARD_HPP

#include "utils/point.hpp"
#include "game/board/path.hpp"

struct SDL_Texture;


namespace game::board
{
    extern Point map_size;

    [[maybe_unused]]
    const FPoint camera_margin {50, 50};


    void render_background();
    void calculate_map_size();
    SDL_Texture* map_cache();
    Point cover(Point source, Point output);


    extern vector<float> encounters;
    void init_encounters();
}

#endif // INCLUDE_PRIVATE_BOARD_HPP
