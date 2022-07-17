#include "game/data.hpp"
#include "game/battle/state.hpp"
#include "game/story/scenes.hpp"
#include "game/board/pawn.hpp"
#include "game/board/path.hpp"
#include "utils/random.hpp"
#include <iostream>

using std::endl;
using std::cout;
using game::board::pawn;

namespace game::battle {
    terrain_t terrain = FOREST;
    SDL_Texture* background = nullptr;
    float lifetime = 15;
    float difficulty = 1;
}


void game::battle::load_battle()
{
    crystals.clear();
    bullets.clear();

    terrain = game::board::path_biome(pawn.progress);
    background = texture(terrain);
    auto size = texture_size(terrain);

    player = Player{};
    player.pos.x = size.x / 2;
    player.pos.y = size.y * 3 / 4;
    player.hp = pawn.hp;
    lifetime = 15;
    
    float p = sqrt(1 / difficulty++);
    spawn_crystals(1 + geometric_random(p) % 6);

    story::single(story::STORY_START, SCENE_BATTLE);
}

void game::battle::unload_battle()
{
    pawn.hp = std::min(player.hp, 3);
    game::scene = SCENE_BOARD;
}
