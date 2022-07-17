#include "game/battle/crystal.hpp"
#include "game/battle/tick.hpp"
#include "game/camera.hpp"
#include "utils/random.hpp"
#include <cmath>
#include <algorithm>

using std::abs;

namespace game::battle {
    vector<Crystal> crystals;
    vector<Bullet> bullets;
    u32 base_attack_timer = 0;
}



SDL_Rect game::battle::
get_frame(Crystal const& obj)
{
    auto [width, size] = texture_size(obj);

    u8 frames = width / size;

    u8 frame = static_cast<u8>(abs(obj.frame)) % frames;

    return {
        frame * size,
        0, size, size
    };
}

SDL_Rect game::battle::
get_frame(Bullet const& obj)
{
    auto [width, size] = texture_size(obj);

    u8 frames = width / size;

    u8 frame = static_cast<u8>(abs(obj.frame)) % frames;

    return {
        frame * size,
        0, size, size
    };
}

void game::battle::spawn_crystals(u8 count)
{
    auto screen = camera.size;
    FPoint spawn {
        screen.x / 2.0f,
        screen.y / 4.0f
    };

    auto [x, y] = spawn;

    switch(count % 7) {
    default: return;
    case 1:
        spawn_crystal(spawn);
        break;
    case 2:
        spawn_crystal({x + 100, y - 100});
        spawn_crystal({x - 100, y + 100});
        break;
    case 3:
        spawn_crystal({x + 100, y - 100});
        spawn_crystal(spawn);
        spawn_crystal({x - 100, y + 100});
        break;
    case 4:
        spawn_crystal({x + 100, y - 100});
        spawn_crystal({x - 100, y + 100});
        spawn_crystal({x + 100, y + 100});
        spawn_crystal({x - 100, y - 100});
        break;
    case 5:
        spawn_crystal({x + 100, y - 100});
        spawn_crystal({x - 100, y + 100});
        spawn_crystal({x + 100, y + 100});
        spawn_crystal({x - 100, y - 100});
        spawn_crystal(spawn);
        break;
    case 6:
        spawn_crystal({x + 100, y - 100});
        spawn_crystal({x - 100, y + 100});
        spawn_crystal({x + 100, y + 100});
        spawn_crystal({x - 100, y - 100});
        spawn_crystal({x + 100, y});
        spawn_crystal({x - 100, y});
        break;
    }
}

void game::battle::spawn_crystal(FPoint pos)
{
    Crystal crystal;
    auto max_frame = healthy_crystal_frame_limiter;
    crystal.frame = randomf(0, max_frame + 1);
    crystal.energy= randomf(0, 0.9);
    crystal.type = get_random_element();
    u8 type = static_cast<u8>(crystal.type);
    crystal.pos = {pos.x, pos.y};
    crystal.regeneration_rate = regen_rates[type];

    crystals.push_back(crystal);
}

game::battle::element_t
game::battle::get_random_element()
{
    vector<element_t> available =
        {ELECTRO, GROUND, FIRE, ICE, AIR, DARKNESS};

    for(auto const& crystal : crystals) {
        auto itr = std::find(
            available.begin(),
            available.end(),
            crystal.type
        );
        available.erase(itr);
    }

    return available[random(0, available.size() - 1)];
}

game::battle::element_t
game::battle::opposite(element_t el)
{
    switch(el) {
    default:
    case AIR: // uses white texture
        return DARKNESS;
    case DARKNESS:
        return AIR;

    case FIRE:
        return ICE;
    case ICE:
        return FIRE;

    case ELECTRO:
        return GROUND;
    case GROUND:
        return ELECTRO;
    }
}


void game::battle::tick_crystal(Crystal& obj, u32 ms)
{
    obj.energy += obj.regeneration_rate * ms/1000;
    switch(obj.type) {
    case ELECTRO:
    case FIRE:
    case GROUND:
    case AIR:
    case DARKNESS:
        if(obj.energy > 1) {
            attack(obj);
            obj.energy--;
        }
        break;
    case ICE:
        if(obj.energy > 5)
            obj.rushing = true;
        if(obj.rushing) {
            obj.energy -= ms/100.0f;
            obj.rushed_energy += ms/100.0f;
            if(obj.rushed_energy >= 1) {
                obj.rushed_energy--;
                attack(obj);
            }
        }
        if(obj.energy < 1)
            obj.rushing = false;
        break;
    }

    obj.frame += crystal_animation_speed * ms/1000;
    if(obj.frame >= healthy_crystal_frame_limiter)
        obj.frame = obj.frame * -1 - 0.9;
}

game::battle::Bullet*
game::battle::spawn_bullet(Crystal const& obj,
                           float direction)
{
    Bullet bullet;
    bullet.pos = obj.pos;
    bullet.direction = direction;
    if(random(1, 10000) > 3) {
        bullet.type = obj.type;
    } else {
        bullet.type = opposite(obj.type);
    }

    u8 type = static_cast<u8>(bullet.type);
    bullet.speed *= bullet_speed_factor[type];

    bullets.push_back(bullet);
    return &bullets.back();
}

void game::battle::tick_bullet(Bullet& obj, u32 ms)
{
    obj.frame += bullet_animation_speed * ms/1000;

    float distance = obj.speed * ms/1000;
    obj.pos.x += cos(obj.direction) * distance;
    obj.pos.y += sin(obj.direction) * distance;
}

