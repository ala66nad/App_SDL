#include "BackGround.hpp"

//----------------------------------------------------------------------
BackGround::BackGround(SDL_Renderer *renderer) : Entity(renderer)
{
    _filename = "pacman_sprites.png";
    _texture = LoadTexture();
}

//----------------------------------------------------------------------
void BackGround::OnDraw()
{    
    SDL_RenderCopy(_renderer, _texture, &_blueR, &_DestR);
}
//----------------------------------------------------------------------