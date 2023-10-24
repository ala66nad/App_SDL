#pragma once
#include "Entity.hpp"

class Block : public Entity
{
private:    
    int _x{0}, _y{0}, _block{8};
    uint32_t _color;

public:
    Block(SDL_Renderer* renderer, int x, int y, int block, uint32_t color);
    bool OnDraw();
};