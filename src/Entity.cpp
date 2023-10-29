#include "Entity.hpp"

//----------------------------------------------------------------------
Entity::Entity(SDL_Renderer *renderer): _renderer{renderer}
{
    _filename = "pacman_sprites.png";
}

//----------------------------------------------------------------------
Entity::~Entity()
{
    OnCleanUp();
}

//----------------------------------------------------------------------
SDL_Texture* Entity::LoadTexture()
{
    return IMG_LoadTexture(_renderer, _filename.c_str());    
}

//----------------------------------------------------------------------
bool Entity::OnDraw()
{
    SDL_Rect DestR{_x, _y, _block, _block};
    if (SDL_SetRenderDrawColor(_renderer, UNHEX(_color)) != 0)
    {
        std::cout << "Erreur : color Entity > " << SDL_GetError() << std::endl;
    }
    return SDL_RenderFillRect(_renderer, &DestR) == 0;
}

//----------------------------------------------------------------------
void Entity::OnCleanUp()
{
    if (_renderer != NULL)
    {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }
}
//----------------------------------------------------------------------