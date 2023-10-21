#pragma once

#include "Event.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <array>

#define SCALE 3
#define UNHEX(c) ((c >> 8 * 3) & 0xFF), ((c >> 8 * 2) & 0xFF), ((c >> 8 * 1) & 0xFF), ((c >> 8 * 0) & 0xFF)

typedef struct Window
{
    int w;
    int h;
    int s;
} Window;

class App : public Event
{
    private:
        bool running{true};
        uint32_t _limitR{0};
        int _x{50}, _y{300};
        std::array<uint32_t, 4> _fps_limit{1000 / 20, 1000 / 30, 1000 / 60, 1000 / 90};
        SDL_Window *window{nullptr};
        SDL_Renderer *renderer{nullptr};
        Window win{168 * SCALE, 216 * SCALE, SCALE};

    public:
        App();
        ~App();
        int OnExecute();
        void OnEvent(SDL_Event *Event);
        void OnExit();
        void OnKeyDown(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode);
        void OnLoop();
        void OnRender(SDL_Rect rectangle);
        void OnDraw(SDL_Rect rectangle);
        void LimitFPS(uint32_t limit);
        void OnCleanUp();
        void OnError(std::string s);

    public: 
        bool OnInit();
};