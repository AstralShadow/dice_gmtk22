#ifndef INCLUDE_DATA_HPP
#define INCLUDE_DATA_HPP

#include "utils/types.hpp"

namespace game
{
    enum scene_t {
        SCENE_MENU,
        SCENE_BOARD,
        SCENE_BATTLE,
        SCENE_STORY
    } extern scene;

    namespace story {
        void play(u32 id, scene_t next);
        void single(u32 id, scene_t next);
    }

}

#endif // INCLUDE_DATA_HPP
