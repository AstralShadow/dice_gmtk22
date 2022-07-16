#include "core/core.hpp"
#include "game/camera.hpp"
#include <cmath>
#include <array>
#include <SDL2/SDL_render.h>

using core::renderer;
using game::Camera;


void Camera::tick(u32)
{
    //auto dx = target_pos.x - pos.x;
    //auto dy = target_pos.y - pos.y;

    pos.x = target_pos.x;
    pos.y = target_pos.y;
}

void game::cameras_to_screen_size()
{
    std::array camera_list {
        &board::camera
    };

    for(auto camera : camera_list) {
        SDL_GetRendererOutputSize(
            renderer,
            &camera->size.x,
            &camera->size.y
        );
    }
}
