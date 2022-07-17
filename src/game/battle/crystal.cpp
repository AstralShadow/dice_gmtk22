#include "game/battle/crystal.hpp"
#include "game/battle/tick.hpp"
#include "game/camera.hpp"
#include "utils/random.hpp"
#include <cmath>

using std::abs;

namespace game::battle {
    vector<Crystal> crystals;
    vector<Bullet> bullets;
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
    crystal.frame = random(0, max_frame);
    crystal.type = get_random_element();
    u8 type = static_cast<u8>(crystal.type);
    crystal.pos = {pos.x, pos.y};
    crystal.regeneration_rate = regen_rates[type];

    crystals.push_back(crystal);
}

game::battle::element_t
game::battle::get_random_element()
{
    switch(random(0, 5)) {
    default:
    case 0: return ELECTRO;
    case 1: return GROUND;
    case 2: return FIRE;
    case 3: return ICE;
    case 4: return AIR;
    case 5: return DARKNESS;
    }
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
    if(obj.energy > 1) {
        attack(obj);
        obj.energy--;
    }

    obj.frame += crystal_animation_speed * ms/1000;
    if(obj.frame >= healthy_crystal_frame_limiter)
        obj.frame *= -1;
}

void game::battle::spawn_bullet(Crystal const& obj,
                                float direction)
{
    Bullet bullet;
    bullet.pos = obj.pos;
    bullet.direction = direction;
    if(random(1, 100) == 42) {
        bullet.type = opposite(obj.type);
    } else {
        bullet.type = obj.type;
    }

    u8 type = static_cast<u8>(obj.type);
    bullet.speed *= bullet_speed_factor[type];

    bullets.push_back(bullet);
}

void game::battle::tick_bullet(Bullet& obj, u32 ms)
{
    float distance = obj.speed * ms/1000;
    obj.pos.x += cos(obj.direction) * distance;
    obj.pos.y += sin(obj.direction) * distance;
}

