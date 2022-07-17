#include "game/game.hpp"
#include "game/data.hpp"
#include "game/camera.hpp"
#include "game/board/private.hpp"
#include "game/board/pawn.hpp"
#include <vector>
#include <iostream>
#include "utils/random.hpp"
#include "game/battle/state.hpp"

using std::vector;
using std::cout;
using std::endl;


vector<float> game::board::encounters;
static float step = 0.03f; // path per second
static float regen_rate = 0.20f; // hp per second


void game::board::tick(u32 ms)
{
    if(encounters.size() == 0)
        init_encounters();
    camera.tick(ms);

    float old_p = pawn.progress;
    pawn.progress += step * ms/1000;
    pawn.regen_buffer += regen_rate * ms/1000;
    if(pawn.regen_buffer > 1) {
        pawn.regen_buffer--;
        if(pawn.hp < 3)
            pawn.hp++;
    }

    for(float pos : encounters) {
        if(old_p < pos && pos < pawn.progress)
            battle::load_battle();
        if(old_p > pos && pos > pawn.progress)
            battle::load_battle();
    }
    
    if(pawn.progress > 1) {
        pawn.progress = -1;
        encounters.clear();
        init_encounters();
    }

}

void game::board::init_encounters()
{
    cout << "Generating encounters" << endl;

    u8 count = random(2, 5);
    for(u8 i = 0; i < count; i++) {
        float step = 0.8f / count;
        float a = 0.1f + i * step;
        float b = 0.1f + (i + 1) * step;
        encounters.push_back(randomf(a, b));
    }
}
