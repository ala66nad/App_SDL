#pragma once
#include "Entity.hpp"

class BackGround : public Entity
{
    private:
        SDL_Rect _blueR{369, 3, 168, 216};
        SDL_Rect _DestR{0, 0, 0, 0};
        SDL_Texture* _texture{nullptr};
    
    public:
        BackGround(SDL_Renderer *renderer, Window win);
        ~BackGround();
        void OnDraw();
};