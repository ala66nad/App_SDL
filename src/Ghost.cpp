#include "Ghost.hpp"

//----------------------------------------------------------------------
Ghost::Ghost(SDL_Renderer *renderer, int x, int y, int block): Entity(renderer)
{
    _x = x;
    _y = y;
    _block = block;
}

//----------------------------------------------------------------------
void Ghost::OnUpdate(const std::vector<std::shared_ptr<Block>> &b)
{
    OnDraw(0xD82800FF);
}

//----------------------------------------------------------------------
bool Ghost::OnDraw(uint32_t color)
{
    SDL_Rect DestR{_x, _y, _block, _block};
    if (SDL_SetRenderDrawColor(_renderer, UNHEX(color)) != 0)
    {
        std::cout << "Erreur : color block > " << SDL_GetError() << std::endl;
    }
    return SDL_RenderFillRect(_renderer, &DestR) == 0;
}

//----------------------------------------------------------------------
bool Ghost::CollisionWithWall(const std::shared_ptr<Block> &b)
{
    return (_x + _block + _vx > b->_x &&
            _x + _vx < b->_x + b->_block &&
            _y + _block + _vy > b->_y &&
            _y + _vy < b->_y + b->_block);
}

//----------------------------------------------------------------------
void Ghost::CollisionDoor(const std::vector<std::shared_ptr<Block>> &bg)
{
    for (const auto &b : bg)
    {
        if (CollisionWithWall(b))
        {
            if (_vx == -_velocity)
                _x = 19 * _block;
            else if (_vx == _velocity)
                _x = _block;
        }
    }
}
//----------------------------------------------------------------------