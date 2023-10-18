#include "App.hpp"

//----------------------------------------------------------------------
App::App()
{
    running = true;
}

//----------------------------------------------------------------------
App::~App()
{
    std::cout << "Destructeur de App " << this << std::endl;
}

//----------------------------------------------------------------------
int App::OnExecute()
{
    if (OnInit() == false)
    {
        return -1;
    }
    OnLoop();
    OnCleanUp();
    return 0;
}

//----------------------------------------------------------------------
void App::OnLoop()
{
    uint32_t frame_limit = 0;
    SDL_Rect rectangle{_x, _y, 200, 150};
    SDL_Event Event;
    while (running)
    {
        while (SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        frame_limit = SDL_GetTicks() + _fps_limit[_limitR];
        OnRender(rectangle);
        LimitFPS(frame_limit);
        rectangle.x = _x;
        rectangle.y = _y;
    }
}

//----------------------------------------------------------------------
void App::OnRender(SDL_Rect rectangle)
{
    if (SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255) != 0)
        OnError("Impossible de changer la couleur du rendu");
    SDL_RenderClear(renderer);
    OnDraw(rectangle);
    SDL_RenderPresent(renderer);
}

//----------------------------------------------------------------------
void App::OnDraw(SDL_Rect rectangle)
{
    if (SDL_SetRenderDrawColor(renderer, UNHEX(0xFF88EEFF)) != 0)
    {
        OnError("Impossible de changer la couleur du rendu");
    }

    if (SDL_RenderFillRect(renderer, &rectangle) != 0)
    {
        OnError("Impossible de dessiner");
    }
}

//----------------------------------------------------------------------
void App::OnEvent(SDL_Event *Event)
{
    Event::OnEvent(Event);
}

//----------------------------------------------------------------------
void App::OnExit()
{
    running = false;
}

//----------------------------------------------------------------------
void App::OnKeyDown(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode)
{
    int volosity = 10;
    switch (sym)
    {
    case SDLK_KP_PLUS:
        _limitR = _limitR < std::size(_fps_limit) - 1 ? _limitR + 1 : 0;
        break;
    case SDLK_RIGHT:
        _x += volosity;
        break;
    case SDLK_LEFT:
        _x -= volosity;
        break;
    case SDLK_UP:
        _y -= volosity;
        break;
    case SDLK_DOWN:
        _y += volosity;
        break;
    default:
        break;
    }
}

//----------------------------------------------------------------------
void App::LimitFPS(uint32_t limit)
{
    uint32_t ticks = SDL_GetTicks();
    if (limit < ticks)
        return;
    if (limit > ticks + _fps_limit[_limitR])
        SDL_Delay(_fps_limit[_limitR]);
    else
        SDL_Delay(limit - ticks);
}

//----------------------------------------------------------------------
void App::OnCleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//----------------------------------------------------------------------
void App::OnError(std::string s)
{
    std::cout << "Erreur : " << s << " > " << SDL_GetError() << std::endl;
    OnCleanUp();
}
//----------------------------------------------------------------------