#include "BackGround.hpp"

//----------------------------------------------------------------------
BackGround::BackGround(SDL_Renderer *renderer, int scale) : Entity(renderer)
{
    _filename = "pacman_sprites.png";
    _texture = LoadTexture();
    SDL_Rect tmpR{0, 0, 168 * scale, 216 * scale};
    _DestR = tmpR;
}

//----------------------------------------------------------------------
void BackGround::OnDraw()
{    
    SDL_RenderCopy(_renderer, _texture, &_blueR, &_DestR);
}
//----------------------------------------------------------------------