#ifndef INCLUDE_SCENES_HPP
#define INCLUDE_SCENES_HPP

#include "game/textures.hpp"
#include <vector>
#include <array>
#include <string>

using std::array;
using std::vector;
using std::string;


namespace game::story {

    enum : u32 { // TODO rename to SCENE_*
        STORY_INTRO = 0,
        STORY_START = 1,
        STORY_GAME_OVER = 2
    };

    const array scenes {
        vector<string> { // intro
            TX_STORY "title.png",
            TX_STORY "intro/1.png",
            TX_STORY "intro/2.png",
            TX_STORY "intro/3.png",
            TX_STORY "intro/4.png",
            TX_STORY "intro/5.png",
            TX_STORY "intro/6.png",
            TX_STORY "intro/7.png",
            TX_STORY "intro/8.png",
            TX_STORY "intro/9.png",
            TX_STORY "intro/10.png",
            TX_STORY "intro/11.png",
            TX_STORY "intro/12.png"
        },
        vector<string> { // level start
            TX_STORY "start_game/1.png",
            TX_STORY "start_game/2.png",
            TX_STORY "start_game/3.png",
        },
        vector<string> { // game over
            TX_STORY "gameover/1.png",
            TX_STORY "gameover/2.png"
        }
    };

}

#endif // INCLUDE_SCENES_HPP
