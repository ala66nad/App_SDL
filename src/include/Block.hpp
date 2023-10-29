#pragma once
#include "Entity.hpp"

class Block : public Entity
{
private:        

public:
    Block(SDL_Renderer* renderer, int x, int y, int block, uint32_t color);

};