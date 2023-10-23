# pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

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