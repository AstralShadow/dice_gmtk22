#include "game/data.hpp"
#include "game/battle/state.hpp"
#include "game/board/pawn.hpp"
#include "game/board/path.hpp"


namespace game { terrain_t battle::terrain = FOREST; }

using game::board::pawn;


void game::battle::load_battle()
{
    terrain = game::board::path_biome(pawn.progress);
    background = texture(terrain);

    player.hp = pawn.hp;
    game::scene = SCENE_BATTLE;
}

void game::battle::unload_battle()
{
    pawn.hp = player.hp;
    game::scene = SCENE_BOARD;
}
