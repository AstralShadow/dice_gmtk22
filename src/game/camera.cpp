#include "core/core.hpp"
#include "game/camera.hpp"
#include <cmath>
#include <array>
#include <SDL2/SDL_render.h>

using core::renderer;
using game::Camera;

void Camera::tick(u32 ms)
{
    auto dx = target_pos.x - pos.x;
    auto dy = target_pos.y - pos.y;

    auto angle = std::atan2(dy, dx);
    auto distance = std::hypot(dx, dy);
    
    auto step = speed * ms/1000;
    distance = std::min(distance, step);

    pos.x += cos(angle) * distance;
    pos.y += sin(angle) * distance;
}

void game::cameras_to_screen_size()
{
    std::array camera_list {
        &board::camera,
        &battle::camera
    };

    for(auto camera : camera_list) {
        SDL_GetRendererOutputSize(
            renderer,
            &camera->size.x,
            &camera->size.y
        );
    }
}
