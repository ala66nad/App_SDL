#pragma once
#include "Entity.hpp"

class BackGround : public Entity
{
    private:
        std::vector<SDL_Rect> _OrigR{{369, 3, 168, 216}, {540, 3, 168, 216}};
        SDL_Rect _DestR{0, 0, 0, 0};
        SDL_Texture* _texture{nullptr};
    
    public: 
        int orig{0};

    public:        
        BackGround(SDL_Renderer *renderer, Window win);
        ~BackGround();
        void OnDraw();
};