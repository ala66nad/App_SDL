#include "PowerDot.hpp"

//----------------------------------------------------------------------
PowerDot::PowerDot(SDL_Renderer *renderer, int x, int y, int block, int scale) : Entity(renderer)
{
    _texture = LoadTexture();
    _x = x;
    _y = y;
    _block = block;
    _scale = scale;
}

//----------------------------------------------------------------------
void PowerDot::OnDraw()
{
    int p_dot = 7 * _scale;
    int pos = _block / 2 - p_dot / 2;
    SDL_Rect DestR{_x + pos, _y + pos, p_dot, p_dot};
    SDL_RenderCopy(_renderer, _texture, &_OrigR, &DestR);
}

//----------------------------------------------------------------------