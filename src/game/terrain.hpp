#ifndef INCLUDE_TERRAIN_HPP
#define INCLUDE_TERRAIN_HPP

#include "utils/point.hpp"
#include <vector>

using std::vector;
struct SDL_Texture;


namespace game
{
    enum terrain_t
    {
        FOREST = 0,
        MEADOW = 1,
        BEACH = 2
    };

    struct Circle
    {
        FPoint pos;
        float radius;
    };

    [[maybe_unused]]
    const vector<Circle> terrain_obstacles[3] = {
        { // FOREST
            {{33+37, 191+37}, 37},
            {{121+45, 129+45}, 45},
            {{96+73,-14+73}, 73},
            {{276+50,-31+50}, 50},

            {{822+54, -5+54}, 54},
            {{896+100, -25+100}, 100},
            {{929+100, 217+100}, 100},
            {{1015+86, 448+86}, 86},
            {{612+50, 543+50}, 50},
            {{-49+104, 467+104}, 104}
        },
        { // MEADOW
            {{250+25, 218+25}, 25},
            {{221+29, 182+29}, 29},

            {{556+38, 397+38}, 38},
            {{497+41, 383+41}, 41},

            {{776+36, 200+36}, 36},
            {{815+39, 180+39}, 39},
            {{842+37, 165+37}, 37}
        },
        {} // BEACH (hardcore, huh?)
    };

    SDL_Texture* texture(terrain_t);
    Point texture_size(terrain_t);
}

#endif // INCLUDE_TERRAIN_HPP
