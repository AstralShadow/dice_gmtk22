#ifndef INCLUDE_CAMERA_HPP
#define INCLUDE_CAMERA_HPP

#include "utils/types.hpp"
#include "utils/point.hpp"

namespace game
{
    struct Camera
    {
        FPoint pos {0, 0};
        FPoint motion {0, 0};
        FPoint target_pos {0, 0};
        Point size {0, 0};

        void tick(u32 ms);
    };

    extern Camera board_camera;

    void cameras_to_screen_size();
}

#endif // INCLUDE_CAMERA_HPP
