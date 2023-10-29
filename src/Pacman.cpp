#include "Pacman.hpp"

Pacman::Pacman(SDL_Renderer* renderer, int x, int y, int block) : Entity(renderer)
{
    _x = x;
    _y = y;
    _block = block;
    _color = 0xFFFF00FF;
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
void Pacman::CollisionDoor(const std::vector<std::shared_ptr<Block>> &bg)
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
bool Pacman::CollisionWithDot(const std::shared_ptr<Dot> &b)
{
    return (_x + _block + _vx > b->_x &&
            _x + _vx < b->_x + b->_block &&
            _y + _block + _vy > b->_y &&
            _y + _vy < b->_y + b->_block);
}

//----------------------------------------------------------------------
void Pacman::CollisionDot(const std::vector<std::shared_ptr<Dot>> &dots)
{
    for (const auto &d : dots)
    {
        if (CollisionWithDot(d))
            d->_blockD = 0;
        d->OnDraw();
    }
}

//----------------------------------------------------------------------
bool Pacman::CollisionWithPowerDot(const std::shared_ptr<PowerDot> &b)
{
    return (_x + _block + _vx > b->_x &&
            _x + _vx < b->_x + b->_block &&
            _y + _block + _vy > b->_y &&
            _y + _vy < b->_y + b->_block);
}

//----------------------------------------------------------------------
void Pacman::CollisionPowerDot(const std::vector<std::shared_ptr<PowerDot>> &dots)
{
    for (const auto &d : dots)
    {
        if (CollisionWithPowerDot(d))
            d->_blockD = 0;
        d->OnDraw();
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