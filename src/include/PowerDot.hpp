#pragma once
#include "Entity.hpp"

class PowerDot : public Entity
{
    private:        
        SDL_Rect _OrigR{9, 79, 7, 7};        
        SDL_Texture* _texture{nullptr};
    
    public:
        int _x{0}, _y{0}, _block{24}, _scale{3}, _blockD{7};

    public:
        PowerDot(SDL_Renderer *renderer, int x, int y, int block, int scale);
        void OnDraw();

};