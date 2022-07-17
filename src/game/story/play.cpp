#include "game/data.hpp"
#include "game/story/story.hpp"
#include "game/story/scenes.hpp"
#include <iostream>
#include "utils/random.hpp"

using std::cout;
using std::endl;


namespace game::story {
    scene_t next;
    u32 playing = 0;
    u32 frame = 0;
    float progress = 0;
    bool oneshot = false;
}

void game::story::play(u32 id, scene_t _next)
{
    game::scene = SCENE_STORY;
    next = _next;

    playing = id;
    frame = 0;
    progress = 0;
    oneshot = false;
}

void game::story::single(u32 id, scene_t _next)
{
    if(scenes[id].size() == 0) {
        game::scene = _next;
        return;
    }

    game::scene = SCENE_STORY;
    next = _next;

    playing = id;
    progress = 0;
    frame = random(0, scenes[id].size() - 1);
    oneshot = true;
}
