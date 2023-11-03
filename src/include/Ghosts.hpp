#pragma once

#include "SDL2/SDL.h"
#include "Ghost.hpp"
#include <memory>


class Ghosts
{
    private:
        SDL_Renderer *_renderer;
        int _block;
        std::shared_ptr<Ghost> _ghostRed;
        std::shared_ptr<Ghost> _ghostPink;
        std::shared_ptr<Ghost> _ghostInk;
        std::shared_ptr<Ghost> _ghostClyde;

    public:
        Ghosts(SDL_Renderer *renderer, int block);
        void OnUpdate(const std::vector<std::shared_ptr<Block>> &b, const std::vector<std::shared_ptr<Block>> &b1);
};