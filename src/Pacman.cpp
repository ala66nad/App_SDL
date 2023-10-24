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
void Pacman::OnUpdate(const std::vector<std::shared_ptr<Block>> &bg)
{
    if (LastKey == 5)
    {
        _vx = 0;
        _vy = 0;
    }
    else if (LastKey == down)
    {
        _vy = 4;
        _vx = 0;
    }       
    else if (LastKey == up)
    {
        _vy = -4;
        _vx = 0;
    }
    else if (LastKey == right)
    {
        _vx = 4;
        _vy = 0;
    }        
    else if (LastKey == left)
    {
        _vx = -4;
        _vy = 0;
    }

    for (const auto &b : bg)
    {       
        if (CollisionWithWall(b))
        {
            _vx = 0;
            _vy = 0;
        }
    }
    _x += _vx;
    _y += _vy;
    OnDraw();
}

//----------------------------------------------------------------------
bool Pacman::CollisionWithWall(const std::shared_ptr<Block> &b)
{
    return (_x + _block + _vx > b->_x &&
            _x + _vx < b->_x + b->_block &&
            _y + _block + _vy > b->_y &&
            _y + _vy < b->_y + b->_block);
}

//----------------------------------------------------------------------