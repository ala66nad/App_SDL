#pragma once

#include "Event.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "BackGround.hpp"
#include "Map.hpp"
#include "Pacman.hpp"
#include "Ghosts.hpp"
#include "Ghost.hpp"
#include <iostream>
#include <memory>
#include <array>
#include <vector>

#define SCALE 3

class App : public Event
{
    private:
        bool running{true};
        uint32_t _limitR{1};
        int _x{50}, _y{300}, _block{8};
        std::array<uint32_t, 4> _fps_limit{1000 / 20, 1000 / 30, 1000 / 60, 1000 / 90};
        Window _win{168 * SCALE, 216 * SCALE, SCALE};
        std::shared_ptr<RenderWindow> window{nullptr};
        std::unique_ptr<BackGround> _backGround{nullptr};
        std::unique_ptr<Map> _map;
        std::unique_ptr<Pacman> _pacman;
        std::unique_ptr<Ghosts> _ghosts;

    public:
        App();
        ~App();
        int OnExecute();
        void OnDraw(auto &block);
        std::vector<std::shared_ptr<Block>> AddVec(std::vector<std::shared_ptr<Block>> &b1, std::vector<std::shared_ptr<Block>> &b2);
        void OnEvent(SDL_Event *Event);
        void OnExit();
        void OnKeyDown(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode);
        void OnLoop();        
        void LimitFPS(uint32_t limit);
        void OnCleanUp();
        void OnError(std::string s);

    public: 
        bool OnInit();
};