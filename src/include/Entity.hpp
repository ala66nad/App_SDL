# pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

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
        int _x, y;

    protected:        
        std::string _filename;
        SDL_Renderer *_renderer{nullptr};

    public :    
        Entity(SDL_Renderer *renderer);
        ~Entity();
        SDL_Texture* LoadTexture();
        void OnCleanUp();
};