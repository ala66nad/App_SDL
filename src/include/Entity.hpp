#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>


#define UNHEX(c) ((c >> 8 * 3) & 0xFF), ((c >> 8 * 2) & 0xFF), ((c >> 8 * 1) & 0xFF), ((c >> 8 * 0) & 0xFF)

struct Window
{
    int w;
    int h;
    int s;
};

enum Direction
{
    right,
    left,
    up,
    down
};

class Entity
{
    private:        

    protected:
        std::string _filename;
        SDL_Renderer *_renderer{nullptr};
    
    public:
        int _x{0}, _y{0}, _block{0};
        int _vx{0}, _vy{0}, _velocity{4};
        uint32_t _color;

    public :    
        Entity(SDL_Renderer *renderer);
        ~Entity();
        SDL_Texture* LoadTexture();
        bool OnDraw();        
        void OnCleanUp();
};