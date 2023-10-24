#pragma once
#include "Entity.hpp"

class Block : public Entity
{
private:        
    uint32_t _color;

public:
    int _x{0}, _y{0}, _block{24};

public:
    Block(SDL_Renderer* renderer, int x, int y, int block, uint32_t color);
    bool OnDraw();
};