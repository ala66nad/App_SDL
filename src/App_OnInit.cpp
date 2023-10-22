#include "App.hpp"

bool App::OnInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        OnError("Initialisation SDL");
        return false;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        OnError("Initialisation IMG");
        return false;
    }
    
    if(window->OnInit() == false)
    {
        OnError("Initialisation RenderWindow");
        return false;
    }

    return true;
}