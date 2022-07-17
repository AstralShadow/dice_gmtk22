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

#define TX_PRINCESS "assets/princess.png"
        TX_PRINCESS,
#define TX_PRINCE "assets/prince.png"
        TX_PRINCE,
#define TX_PLAYER "assets/player/"
        TX_PLAYER "lime.png",
        TX_PLAYER "yellow.png",
        TX_PLAYER "orange.png",
        TX_PLAYER "red.png",
#define TX_PAWN "assets/pawn/"
        TX_PAWN "lime.png",
        TX_PAWN "yellow.png",
        TX_PAWN "orange.png",
        TX_PAWN "red.png",

        "assets/arena/forest.png",
        "assets/arena/meadow.png",
        "assets/arena/beach.png",

#define HUD_DICE "assets/hud/dice.png"
        HUD_DICE,
#define HUD_DICE_EMPTY "assets/hud/dice_empty.png"
        HUD_DICE_EMPTY,

#define TX_CRYSTAL "assets/crystals/"
        TX_CRYSTAL "air.png",
        TX_CRYSTAL "electro.png",
        TX_CRYSTAL "ground.png",
        TX_CRYSTAL "darkness.png",
        TX_CRYSTAL "fire.png",
        TX_CRYSTAL "ice.png",
#define TX_BULLET "assets/bullets/"
        TX_BULLET "air.png",
        TX_BULLET "electro.png",
        TX_BULLET "ground.png",
        TX_BULLET "darkness.png",
        TX_BULLET "fire.png",
        TX_BULLET "ice.png",
    };

    extern std::vector<SDL_Surface*> surfaces;
    extern std::vector<SDL_Texture*> textures;

    void load_textures();
    SDL_Texture* texture(std::string const&);
    SDL_Surface* surface(std::string const&);
    Point texture_size(std::string const&);
}

#endif // INCLUDE_TEXTURES_HPP
