#include "game/game.hpp"
#include "core/core.hpp"
#include "game/story/story.hpp"
#include "game/story/scenes.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

using std::cout;
using std::endl;

auto& rnd = core::renderer;


void game::story::render()
{
    cout << "access " << playing << ':' << frame << endl;
    string name = scenes[playing][frame];
    cout << "name = " << name << endl;
    auto bg = texture(TX_STORY "background.png");
    auto tx = texture(name);
    
    u8 alpha = 255;
    if(progress < 1)
        alpha *= progress;
    if(progress > delay - 1)
        alpha *= 1 - (progress - (delay - 1));

    auto last = scenes[playing].size() - 1;
    bool blend_background = (
        oneshot ||
        (frame == 0 && progress < 1) ||
        (frame == last && progress > 1)
    );

    if(blend_background)
        SDL_SetTextureAlphaMod(bg, alpha);
    SDL_SetTextureAlphaMod(tx, alpha);

    SDL_RenderCopy(rnd, bg, nullptr, nullptr);
    SDL_RenderCopy(rnd, tx, nullptr, nullptr);

    if(blend_background)
        SDL_SetTextureAlphaMod(bg, 255);
    SDL_SetTextureAlphaMod(tx, 255);
}
