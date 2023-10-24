#include "Dot.hpp"

//----------------------------------------------------------------------
Dot::Dot(SDL_Renderer *renderer, int x, int y, int block, int scale) : Entity(renderer)
{
    _texture = LoadTexture();
    _x = x;
    _y = y;
    _block = block;
    _scale = scale;
}

//----------------------------------------------------------------------
void Dot::OnDraw()
{
    int dot = 2 * _scale;
    int pos = _block / 2 - _scale;
    SDL_Rect DestR{_x + pos, _y + pos, dot, dot};
    SDL_RenderCopy(_renderer, _texture, &_OrigR, &DestR);
}

//----------------------------------------------------------------------