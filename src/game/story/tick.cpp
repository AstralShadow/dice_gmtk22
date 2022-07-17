#include "game/game.hpp"
#include "game/data.hpp"
#include "game/story/story.hpp"
#include "game/story/scenes.hpp"
#include <iostream>

using std::cout;
using std::endl;


void game::story::tick(u32 ms)
{
    progress += ms / 1000.0f;

    if(progress >= delay) {
        frame++;
        progress = 0;
        if(oneshot) {
            game::scene = next;
        }
    }

    if(frame >= scenes[playing].size())
        game::scene = next;
}
