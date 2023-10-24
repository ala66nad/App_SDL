#pragma once

#include "Entity.hpp"


class Pacman : public Entity
{
    private:
        int _x{0}, _y{0}, _block{0};
    public:
        Pacman(SDL_Renderer* renderer, int x, int y, int block);
        bool OnDraw();
};