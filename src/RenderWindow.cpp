#include "RenderWindow.hpp"
//----------------------------------------------------------------------
RenderWindow::RenderWindow(std::string title, int w, int h): _title{title}, _w{w}, _h{h}{}

//----------------------------------------------------------------------
bool RenderWindow::OnInit()
{
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, SDL_WINDOW_SHOWN);
    if (_window == NULL)
    {
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == NULL)
    {
        return false;
    }
    return true;
}

//----------------------------------------------------------------------
void RenderWindow::OnCleanUp()
{
    if (_renderer != NULL)
    {
        SDL_DestroyRenderer(_renderer);
    }
    if (_window != NULL)
    {
        SDL_DestroyWindow(_window);
    }
}

//----------------------------------------------------------------------
void RenderWindow::OnClear()
{
    if (SDL_SetRenderDrawColor(_renderer, 33, 33, 33, 255) != 0)
        OnError("Impossible de changer la couleur du rendu");
    SDL_RenderClear(_renderer);
}

//----------------------------------------------------------------------
void RenderWindow::OnDisplay()
{
    SDL_RenderPresent(_renderer);
}

//----------------------------------------------------------------------
void RenderWindow::OnDrawRect(SDL_Rect rectangle, uint32_t color)
{
    if (SDL_SetRenderDrawColor(_renderer, UNHEX(color)) != 0)
    {
        OnError("Impossible de changer la couleur du rendu");
    }

    if (SDL_RenderFillRect(_renderer, &rectangle) != 0)
    {
        OnError("Impossible de dessiner");
    }
}

//----------------------------------------------------------------------
void RenderWindow::OnError(std::string s)
{
    std::cout << "Erreur : " << s << " > " << SDL_GetError() << std::endl;
    OnCleanUp();
}
//----------------------------------------------------------------------