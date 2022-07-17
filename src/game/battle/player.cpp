#include "game/battle/player.hpp"
#include "game/battle/tick.hpp"
#include "game/battle/state.hpp"
#include "game/textures.hpp"
#include <SDL2/SDL_events.h>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using game::texture;


namespace game::battle {
    Player player;
}


static Point get_keyboard_motion()
{
    auto state = SDL_GetKeyboardState(nullptr);
    Point motion {0, 0};

    if(state[SDL_SCANCODE_W]
        || state[SDL_SCANCODE_UP])
        motion.y -= 1;
    if(state[SDL_SCANCODE_S]
        || state[SDL_SCANCODE_DOWN])
        motion.y += 1;
    if(state[SDL_SCANCODE_A]
        || state[SDL_SCANCODE_LEFT])
        motion.x -= 1;
    if(state[SDL_SCANCODE_D]
       || state[SDL_SCANCODE_RIGHT])
        motion.x += 1;

    if(std::abs(motion.x) + std::abs(motion.y) > 1) {
        motion.x *= std::sqrt(2);
        motion.y *= std::sqrt(2);
    }

    return motion;
}

void game::battle::tick_player(u32 ms)
{
    if(player.energy < player.energy_limit) {
        player.energy += player.recharge_rate * ms/1000;
    } else {
        player.energy = player.energy_limit;
    }

    if(player.r_time > 0) {
        tick_player_rush(ms);
    } else {
        auto motion = get_keyboard_motion();
        auto speed = player.speed * ms/1000;

        player.pos.x += motion.x * speed;
        player.pos.y += motion.y * speed;
    }

    
    auto arena = texture_size(terrain);
    auto size = texture_size(player);
    if(player.pos.x < 30) player.pos.x = 30;
    if(player.pos.y < 30) player.pos.y = 30;
    if(player.pos.x > arena.x - 30 - size.x)
        player.pos.x = arena.x - 30 - size.x;
    if(player.pos.y > arena.y - 30 - size.y)
        player.pos.y = arena.y - 30 - size.y;

    auto obstacles = terrain_obstacles
        [static_cast<u8>(terrain)];
}

void game::battle::player_rush(float direction)
{
    if(player.r_time > 0) return;
    if(player.energy < 1) return;

    player.r_direction = direction;
    player.r_time = player.r_duration;
    player.energy--;
}

void game::battle::tick_player_rush(u32 ms)
{
    float distance = ms * player.r_speed / 1000;

    player.pos.x += cos(player.r_direction) * distance;
    player.pos.y += sin(player.r_direction) * distance;

    player.r_time -= ms / 1000.0f;
}


