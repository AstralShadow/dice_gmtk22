#include "game/game.hpp"
#include "core/core.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"
#include "game/textures.hpp"
#include "game/board/private.hpp"
#include "game/battle/state.hpp"

#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;


namespace game
{
    scene_t scene = SCENE_BOARD;
    vector<SDL_Surface*> surfaces;
    vector<SDL_Texture*> textures;

    Camera board::camera;
    Camera battle::camera;
}


void game::init(int, char**)
{
    load_textures();
    battle::load_battle();
}

void game::load_textures()
{
    auto rnd = core::renderer;

    cout << "Loading graphic assets" << endl;
    for(auto file : texture_paths) {
        auto surface = IMG_Load(file);
        if(!surface) {
            cout << "Could not load asset: ";
            cout << file << endl;
            cout << "IMG_Load error: ";
            cout << IMG_GetError() << endl;
        }

        surfaces.push_back(surface);
    }

    cout << "Baking textures" << endl;
    for(auto surface : surfaces) {
        if(!surface) {
            textures.push_back(nullptr);
            continue;
        }

        auto texture= SDL_CreateTextureFromSurface
            (rnd, surface);

        if(!texture) {
            cout << "Could not prepare texture." << endl;
            cout << "SDL error: ";
            cout << SDL_GetError() << endl;
        }

        textures.push_back(texture);
    }

    cout << "Preparing caches" << endl;
    game::cameras_to_screen_size();
    game::board::map_cache();
}
