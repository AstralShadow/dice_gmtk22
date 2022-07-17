#include "game/battle/crystal.hpp"
#include "game/battle/player.hpp"
#include "game/battle/tick.hpp"
#include "game/camera.hpp"
#include "utils/random.hpp"
#include <cmath>

using namespace game::battle;


template<element_t T>
void attack_tpl(Crystal&);

template<>
void attack_tpl<ELECTRO>(Crystal& obj)
{
    auto direction = std::atan2();
    spawn_bullet(obj, direction);
}

template<>
void attack_tpl<GROUND>(Crystal&)
{

}

template<>
void attack_tpl<FIRE>(Crystal&)
{

}

template<>
void attack_tpl<ICE>(Crystal&)
{

}

template<>
void attack_tpl<AIR>(Crystal&)
{

}

template<>
void attack_tpl<DARKNESS>(Crystal&)
{

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

