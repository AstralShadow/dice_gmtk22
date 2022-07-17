#ifndef INCLUDE_STORY_HPP
#define INCLUDE_STORY_HPP

#include "utils/types.hpp"
#include "game/data.hpp"

namespace game::story {
    extern scene_t next;

    extern u32 playing; // id
    extern u32 frame; // index
    extern float progress; // seconds

    extern bool oneshot;

    [[maybe_unused]]
    const float delay = 4.0f; // seconds
}

#endif // INCLUDE_STORY_HPP
