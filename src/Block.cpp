#include "Block.hpp"

Block::Block(SDL_Renderer* renderer, int x, int y, int block, uint32_t color) : Entity(renderer) 
{
     _x = x;
     _y = y;
     _block = block;
     _color = color;
}

//----------------------------------------------------------------------
bool Block::OnDraw()
{    
    SDL_Rect DestR{_x, _y, _block, _block};
    if (SDL_SetRenderDrawColor(_renderer, UNHEX(_color)) != 0)
    {
        std::cout << "Erreur : color block > " << SDL_GetError() << std::endl;
    }        
    return SDL_RenderFillRect(_renderer, &DestR) == 0;
}
//----------------------------------------------------------------------