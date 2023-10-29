#include "Ghost.hpp"

//----------------------------------------------------------------------
Ghost::Ghost(SDL_Renderer *renderer, int x, int y, int block, uint32_t color): Entity(renderer)
{
    _x = x;
    _y = y;
    _block = block;
    _color = color;
   // _vy = -_velocity;
}

//----------------------------------------------------------------------
void Ghost::OnUpdate(const std::vector<std::shared_ptr<Block>> &b)
{
    std::vector<int> res = ControlDirection(b);
    Avance(res[GenereSens(0, res.size() - 1)]);
    ControlCollision(b);
    _x += _vx;
    _y += _vy;
    OnDraw();
}

//----------------------------------------------------------------------
void Ghost::Avance(int v)
{
    switch (v)
    {
    case right:
        _vx = _velocity;
        break;
    case left:
        _vx = -_velocity;
        break;
    case up:
        _vy = -_velocity;
        break;
    case down:
        _vy = _velocity;
        break;
    default:
        break;
    }    
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
void Ghost::ControlCollision(const std::vector<std::shared_ptr<Block>> &bg)
{
    lastVx = _vx;
    lastVy = _vy;
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
bool Ghost::Direction(int x, int y, const std::vector<std::shared_ptr<Block>> bg)
{
    for (auto &b : bg)
    {
        if (_x + _block + x > b->_x &&
            _x + x < b->_x + b->_block &&
            _y + _block + y > b->_y &&
            _y + y < b->_y + b->_block)
        {
            return false;
        }
    }
    return true;
}

//----------------------------------------------------------------------
std::vector<int> Ghost::ControlDirection(const std::vector<std::shared_ptr<Block>> bg)
{
    std::vector<int> res;
    if (Direction(_velocity, 0, bg) && lastVx != -_velocity)
    {
        res.push_back(right);
    }
    if (Direction(-_velocity, 0, bg) && lastVx != _velocity)
    {
        res.push_back(left);
    }
    if (Direction(0, _velocity, bg) && lastVy != -_velocity)
    {
        res.push_back(down);
    }
    if (Direction(0, -_velocity, bg) && lastVy != _velocity)
    {
        res.push_back(up);
    }
    return res;
}

//----------------------------------------------------------------------
double Ghost::GenereSens(int min, int max)
{
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> uniformIntDist(min, max);
    return uniformIntDist(generator);
}
//----------------------------------------------------------------------