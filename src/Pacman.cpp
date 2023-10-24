#include "Pacman.hpp"

Pacman::Pacman(SDL_Renderer* renderer, int x, int y, int block) : Entity(renderer)
{
    _x = x;
    _y = y;
    _block = block;
}

//----------------------------------------------------------------------
bool Pacman::OnDraw()
{    
    SDL_Rect DestR{_x, _y, _block, _block};
    if (SDL_SetRenderDrawColor(_renderer, UNHEX(0xFFFF00FF)) != 0)
    {
        std::cout << "Erreur : color block > " << SDL_GetError() << std::endl;
    }        
    return SDL_RenderFillRect(_renderer, &DestR) == 0;
}

//----------------------------------------------------------------------