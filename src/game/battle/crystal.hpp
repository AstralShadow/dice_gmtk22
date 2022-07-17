#ifndef INCLUDE_CRYSTAL_HPP
#define INCLUDE_CRYSTAL_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"
#include <vector>
#include <array>

using std::vector;
using std::array;
struct SDL_Texture;


namespace game::battle
{
    enum element_t : u8 {
        ELECTRO = 0,
        GROUND = 1,

        FIRE = 2,
        ICE = 3,

        AIR = 4, // uses white color
        DARKNESS = 5
    };

    [[maybe_unused]]
    const std::array<float, 6> regen_rates {
        2.0, // electro
        1.2, // ground
        1.0, // fire
        4.0, // ice
        0.6, // air
        0.2  // darkness
    };

    [[maybe_unused]]
    const std::array<float, 6> bullet_speed_factor {
        4.0, // electro
        0.4, // ground
        1.2, // fire
        1.6, // ice
        1.2, // air
        0.8  // darkness
    };

    [[maybe_unused]]
    const float crystal_animation_speed = 3; // fps
    [[maybe_unused]]
    const float healthy_crystal_frame_limiter = 2;
    [[maybe_unused]]
    const float bullet_animation_speed = 10; // fps


    struct Crystal
    {
        element_t type;

        FPoint pos;
        float frame = 0;

        float speed = 300; // px/s
        float direction = 0;

        float energy = 0; // used for attacks
        float regeneration_rate = 0.7; // en/s
        bool rushing = false; // used for salvo attacks
        float rushed_energy = 0;
    };

    struct Bullet
    {
        element_t type;
        float frame = 0;

        FPoint pos;
        float speed = 150; //px/s
        float lifetime = 10; // used for darkness

        float direction = 0;
    };


    extern vector<Crystal> crystals;
    extern vector<Bullet> bullets;
    extern u32 base_attack_timer; // used when generating starting direction for multidirection attacks

    SDL_Rect get_frame(Crystal const&);
    SDL_Rect get_frame(Bullet const&);

    void spawn_crystals(u8 count);
    void spawn_crystal(FPoint pos);
    element_t get_random_element();
    element_t opposite(element_t);

    void attack(Crystal&);
    Bullet* spawn_bullet(Crystal const&,
                         float direction);
}

namespace game
{
    SDL_Texture* texture(battle::Crystal const&);
    Point texture_size(battle::Crystal const&);
    SDL_Texture* texture(battle::Bullet const&);
    Point texture_size(battle::Bullet const&);
}

#endif // INCLUDE_CRYSTAL_HPP
