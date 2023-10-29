#include "Block.hpp"

//----------------------------------------------------------------------
Block::Block(SDL_Renderer* renderer, int x, int y, int block, uint32_t color) : Entity(renderer) 
{
     _x = x;
     _y = y;
     _block = block;
     _color = color;
}
//----------------------------------------------------------------------