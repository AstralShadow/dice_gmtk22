#include "game/game.hpp"
#include "game/story/story.hpp"

void game::story::click()
{
    if(progress < delay - 1)
        progress = delay - 1;
    else
        progress = delay;
}
