#pragma once
#include "Entity.hpp"

class Dot : public Entity
{
    private:
        int _x{0}, _y{0}, _block{24}, _scale{3};
        SDL_Rect _OrigR{4, 81, 2, 2};        
        SDL_Texture* _texture{nullptr};

    public:
        Dot(SDL_Renderer *renderer, int x, int y, int block, int scale);
        void OnDraw();

};