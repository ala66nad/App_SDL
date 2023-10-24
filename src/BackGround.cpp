#include "BackGround.hpp"

//----------------------------------------------------------------------
BackGround::BackGround(SDL_Renderer *renderer, Window win) : Entity(renderer)
{    
    _texture = LoadTexture();
    _DestR.w = win.w;
    _DestR.h = win.h;
}

//----------------------------------------------------------------------
BackGround::~BackGround()
{
    if (_texture != NULL)
    {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
    }    
}

//----------------------------------------------------------------------
void BackGround::OnDraw()
{    
    SDL_RenderCopy(_renderer, _texture, &_blueR, &_DestR);
}
//----------------------------------------------------------------------