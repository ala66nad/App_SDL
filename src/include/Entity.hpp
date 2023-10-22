# pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
    private:
        int _x, y;        

    public :
        SDL_Rect _blanc{369, 3, 168, 216};
        SDL_Rect _DestR{0, 0, 168 * 3, 216 * 3};
        SDL_Texture *_texture{nullptr};
        Entity(SDL_Texture* texture);        
};