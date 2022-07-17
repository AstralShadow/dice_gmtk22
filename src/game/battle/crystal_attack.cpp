#include "game/battle/crystal.hpp"
#include "game/battle/player.hpp"
#include "game/battle/tick.hpp"
#include "game/camera.hpp"
#include "utils/random.hpp"
#include <cmath>
#include <numbers>

using namespace game::battle;
using game::texture_size;


template<element_t T>
void attack_tpl(Crystal&);

template<>
void attack_tpl<ELECTRO>(Crystal& obj)
{
    auto player_size = texture_size(player);
    FPoint target = {
        player.pos.x + player_size.x / 2,
        player.pos.y + player_size.y * 2 / 3
    };
    FPoint source = {
        obj.pos.x + 50,
        obj.pos.y + 50
    };

    auto dx = target.x - source.x;
    auto dy = target.y - source.y;
    auto direction = std::atan2(dy, dx);

    spawn_bullet(obj, direction);
    auto second = spawn_bullet(obj, direction);
    second->speed *= 0.6;
}

template<>
void attack_tpl<GROUND>(Crystal& obj)
{
    float pi = 3.1415;
    float angle = randomf(0, pi*2);
    int count = 3;
    for(u8 i = 0; i < count; ++i) {
        angle += pi * 2 / count;
        spawn_bullet(obj, angle);
    }
}

template<>
void attack_tpl<FIRE>(Crystal& obj)
{
    float angle = base_attack_timer / 500.0f;
    float pi = 3.1415;
    int count = 7;
    for(u8 i = 0; i < count; ++i) {
        angle += pi * 2 / count;
        spawn_bullet(obj, angle);
    }
}

template<>
void attack_tpl<ICE>(Crystal& obj)
{
    auto player_size = texture_size(player);
    FPoint target = {
        player.pos.x + player_size.x / 2,
        player.pos.y + player_size.y * 2 / 3
    };
    FPoint source = {
        obj.pos.x + 50,
        obj.pos.y + 50
    };

    auto dx = target.x - source.x;
    auto dy = target.y - source.y;
    auto direction = std::atan2(dy, dx);

    spawn_bullet(obj, direction);
}

template<>
void attack_tpl<AIR>(Crystal& obj)
{
    float pi = 3.1415;
    float angle = pi / 2;
    int count = 16;
    for(u8 i = 0; i < count; ++i) {
        angle += pi * 2 / count;
        spawn_bullet(obj, angle);
    }
}

template<>
void attack_tpl<DARKNESS>(Crystal& obj)
{
    attack_tpl<ICE>(obj);
}


void game::battle::attack(Crystal& obj)
{
    switch(obj.type) {
    case ELECTRO:
        attack_tpl<ELECTRO>(obj);
        break;
    case GROUND:
        attack_tpl<GROUND>(obj);
        break;
    case FIRE:
        attack_tpl<FIRE>(obj);
        break;
    case ICE:
        attack_tpl<ICE>(obj);
        break;
    case AIR:
        attack_tpl<AIR>(obj);
        break;
    case DARKNESS:
        attack_tpl<DARKNESS>(obj);
        break;
    }
}

