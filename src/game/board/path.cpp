#include "game/board/path.hpp"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;


FPoint game::board::path_pos(float progress)
{
    progress = std::abs(progress);
    float length = progress * path_length();

    FPoint prev = path[0];
    for(u32 i = 1; i < path.size(); ++i) {
        FPoint next = path[i];

        float dx = next.x - prev.x;
        float dy = next.y - prev.y;
        float step = std::hypot(dy, dx);

        if(step < length) {
            length -= step;
            prev = next;
            continue;
        }

        float angle = std::atan2(dy, dx);
        return {
            prev.x + length * std::cos(angle),
            prev.y + length * std::sin(angle),
        };
    }
    return {1024, 576};
}

using game::board::terrain_t;
terrain_t game::board::path_biome(float progress)
{
    progress = std::abs(progress);
    auto biome = terrain_data[0].second;

    for(auto data : terrain_data) {
        if(progress < data.first)
            return biome;

        biome = data.second;
    }

    return biome;
}
