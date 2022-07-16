#ifndef INCLUDE_RENDER_HPP
#define INCLUDE_RENDER_HPP

struct SDL_Texture;
struct SDL_Rect;


namespace game::battle
{
    void render();
    void render_background();
    void render_entity(SDL_Texture*, SDL_Rect const&);

    void render_player();
    void render_enemies();
    void render_bullets();
}

#endif // INCLUDE_RENDER_HPP
