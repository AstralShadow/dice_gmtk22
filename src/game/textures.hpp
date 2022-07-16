#ifndef INCLUDE_TEXTURES_HPP
#define INCLUDE_TEXTURES_HPP

#include "utils/point.hpp"
#include <vector>
#include <string>
#include <array>

struct SDL_Surface;
struct SDL_Texture;


namespace game
{
    [[maybe_unused]]
    std::array const texture_paths {
#define TEXTURE_MAP "assets/map.png"
        TEXTURE_MAP,
    };

    extern std::vector<SDL_Surface*> surfaces;
    extern std::vector<SDL_Texture*> textures;

    void load_textures();
    SDL_Texture* texture(std::string const&);
    SDL_Surface* surface(std::string const&);
    Point texture_size(std::string const&);
}

#endif // INCLUDE_TEXTURES_HPP
