#include "utils/types.hpp"
#include "game/textures.hpp"
#include <string>
#include <iostream>
#include <SDL_render.h>

using std::string;
using std::cout;
using std::endl;


SDL_Surface* game::surface(string const& query)
{
    for(u32 i = 0; i < texture_paths.size(); ++i) {
        string path = texture_paths[i];
        if(path == query) {
            return surfaces[i];
        }
    }

    cout << "Could not find surface: ";
    cout << query << endl;

    return nullptr;
}

SDL_Texture* game::texture(string const& query)
{
    for(u32 i = 0; i < texture_paths.size(); ++i) {
        string path = texture_paths[i];
        if(path == query) {
            return textures[i];
        }
    }

    cout << "Could not find texture: ";
    cout << query << endl;

    return nullptr;
}

Point game::texture_size(string const& query)
{

    for(u32 i = 0; i < texture_paths.size(); ++i) {
        string path = texture_paths[i];
        if(path == query) {
            auto surface = surfaces[i];
            return {surface->w, surface->h};
        }
    }

    cout << "Could not find texture: ";
    cout << query << endl;

    return {0, 0};
}
