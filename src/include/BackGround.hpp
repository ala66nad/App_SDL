#pragma once
#include "Entity.hpp"

class BackGround : public Entity
{
    private:
        SDL_Rect _blueR{369, 3, 168, 216};
        SDL_Rect _DestR;
        SDL_Texture* _texture{nullptr};
    
    public:
        BackGround(SDL_Renderer *renderer, int scale);
        void OnDraw();
};