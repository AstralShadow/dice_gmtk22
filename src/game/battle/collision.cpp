#include "game/battle/player.hpp"
#include "game/battle/crystal.hpp"
#include "game/battle/state.hpp"
#include "game/battle/tick.hpp"
#include "game/camera.hpp"
#include <cmath>


void game::battle::player_collisions(u32)
{
    auto psize = texture_size(player);
    FPoint bsize {66, 66};

    FPoint p1 {
        player.pos.x + psize.x / 2,
        player.pos.y + psize.y * 2 / 3
    };
    auto range = psize.y / 3 + 20;

    for(u32 i = 0; i < bullets.size(); ++i) {
        auto& bullet = bullets[i];
        FPoint p2 {
            bullet.pos.x + bsize.x / 2,
            bullet.pos.y + bsize.y / 2
        };
        auto dist = hypot(p1.x - p2.x, p1.y - p2.y);

        if(dist < range) {
            player.hp--;

            if(player.hp < 0) {
                game_over();
                return;
            }

            bullets.erase(bullets.begin() + i);
            i--;
        }
    }
}

void game::battle::bullet_collisions(u32)
{
    auto screen = camera.size;
    /* With border */
    for(u32 i = 0; i < bullets.size(); ++i) {
        auto bullet = bullets[i];
        auto x = bullet.pos.x;
        auto y = bullet.pos.y;
        if(x < 0) goto erase;
        if(y < 0) goto erase;
        if(x > screen.x - 20) goto erase;
        if(y > screen.y - 20) goto erase;

        continue;
        erase:
        bullets.erase(bullets.begin() + i--);
    }

    /* With obstacles */
    auto obstacles = terrain_obstacles
        [static_cast<u8>(terrain)];

    for(auto obstacle : obstacles)
    for(u32 i = 0; i < bullets.size(); ++i) {
        auto bullet = bullets[i];
        auto dx = bullet.pos.x+33 - obstacle.pos.x;
        auto dy = bullet.pos.y+33 - obstacle.pos.y;
        auto distance = std::hypot(dx, dy);
        auto range = obstacle.radius + 20;

        if(distance < range)
            bullets.erase(bullets.begin() + i--);
    }
}
