#ifndef INCLUDE_CORE_GAME_HPP
#define INCLUDE_CORE_GAME_HPP

struct SDL_KeyboardEvent;
struct SDL_MouseButtonEvent;
struct SDL_MouseMotionEvent;


namespace game
{
    void init(int, char**);

    void tick();
    void render();

    template<typename event_t>
    extern void handle_event(event_t&);
}

#endif // INCLUDE_CORE_GAME_HPP
