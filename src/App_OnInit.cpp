#include "App.hpp"

bool App::OnInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        OnError("Initialisation SDL");
        return false;
    }

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win.w, win.h, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        OnError("Creation de la fenetre a echouee");
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        OnError("Impossible de creer le rendu");
        return false;
    }
    
    return true;
}