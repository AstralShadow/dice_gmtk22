#include "game/data.hpp"
#include "game/battle/state.hpp"
#include "game/board/pawn.hpp"
#include "game/board/path.hpp"


namespace game::battle {
    terrain_t terrain = FOREST;
    SDL_Texture* background = nullptr;
}

using game::board::pawn;


void game::battle::load_battle()
{
    terrain = game::board::path_biome(pawn.progress);
    background = texture(terrain);
    auto size = texture_size(terrain);

    player.hp = pawn.hp;
    player.pos.x = size.x / 2;
    player.pos.y = size.y * 3 / 4;
    game::scene = SCENE_BATTLE;
}

void game::battle::unload_battle()
{
    pawn.hp = player.hp;
    game::scene = SCENE_BOARD;
}
