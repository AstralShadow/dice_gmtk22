#ifndef INCLUDE_RENDER_HPP
#define INCLUDE_RENDER_HPP

#include "utils/point.hpp"

struct SDL_Texture;
struct SDL_Rect;


namespace game::battle
{
    struct Crystal;
    struct Bullet;

    void render();
    void render_background();
    void render_entity(SDL_Texture*,
                       SDL_Rect const* src,
                       SDL_Rect const* dst);

    void render_player();
    void render_crystal(Crystal const&);
    void render_bullet(Bullet const&);

    void render_hud();
    void render_energy();

    /** Transforms sceen coordinate to game coordinate */
    FPoint localize(FPoint);
}

#endif // INCLUDE_RENDER_HPP
