#include "Entity.hpp"


//----------------------------------------------------------------------
Entity::Entity(SDL_Renderer *renderer): _renderer{renderer}
{
    _filename = "pacman_sprites.png";
}

//----------------------------------------------------------------------
SDL_Texture* Entity::LoadTexture()
{
    return IMG_LoadTexture(_renderer, _filename.c_str());    
}

//----------------------------------------------------------------------
Entity::~Entity()
{
    OnCleanUp();
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