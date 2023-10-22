#include "App.hpp"
#include "Entity.hpp"

//----------------------------------------------------------------------
App::App()
{
    window = std::make_shared<RenderWindow>("game", _win.w, _win.h);    
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
    SDL_Rect rectangle{0, 0, _block, _block};    
    auto entity = std::make_shared<Entity>(window->LoadTexture("pacman_sprites.png"));
    SDL_Event Event;
    while (running)
    {
        
        while (SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        frame_limit = SDL_GetTicks() + _fps_limit[_limitR];
        window->OnClear();
        window->OnDrawEntity(entity);
        for (size_t i = 0; i < 21; i++)
        {
            rectangle.x = i*24;            
            window->OnDrawRect(rectangle, 0xFF22EE99);
        }        
        window->OnDisplay();
        LimitFPS(frame_limit);
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
    window->OnCleanUp();
    SDL_Quit();
    running = false;
}

//----------------------------------------------------------------------
void App::OnError(std::string s)
{
    std::cout << "Erreur : " << s << " > " << SDL_GetError() << std::endl;
    OnCleanUp();
}
//----------------------------------------------------------------------