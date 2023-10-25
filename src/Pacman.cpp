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
    ControlKey();
    ControlCollisionVH(bg);
    ControlCollision(bg);
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
void Pacman::ControlCollision(const std::vector<std::shared_ptr<Block>> &bg)
{
    for (const auto &b : bg)
    {
        if (CollisionWithWall(b))
        {
            _vx = 0;
            _vy = 0;
        }
    }
}

//----------------------------------------------------------------------
void Pacman::ControlCollisionVH(const std::vector<std::shared_ptr<Block>> &bg)
{
    for (const auto &b : bg)
    {
        if (CollisionWithWall(b))
        {
            if (LastKey == right || LastKey == left)
            {
                _vx = 0;
                return;
            }
            if (LastKey == up || LastKey == down)
            {
                _vy = 0;
                return;
            }
        }
    }
}

//----------------------------------------------------------------------
void Pacman::ControlKey()
{
    switch (LastKey)
    {
    case 5:
        _vx = 0;
        _vy = 0;
        break;
    case down:
        _vy = _velocity;
        break;
    case up:
        _vy = -_velocity;
        break;
    case right:
        _vx = _velocity;
        break;
    case left:
        _vx = -_velocity;
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------