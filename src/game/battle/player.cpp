#include "game/battle/player.hpp"
#include "game/textures.hpp"

using game::texture;

namespace game::battle {
    Player player;
}


SDL_Texture* game::battle::player_texture()
{
    switch(player.hp) {
    case 3:
        return texture(TX_PLAYER "lime.png");
    case 2:
        return texture(TX_PLAYER  "yellow.png");
    case 1:
        return texture(TX_PLAYER "orange.png");
    case 0:
        return texture(TX_PLAYER "red.png");
    }

    return nullptr;
}