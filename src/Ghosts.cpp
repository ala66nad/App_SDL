#include "Ghosts.hpp"

Ghosts::Ghosts(SDL_Renderer *renderer, int block) : _renderer{renderer}, _block{block}
{
    _ghostRed = std::make_shared<Ghost>(_renderer, 10 * _block, 10 * _block, _block, 0xD82800FF);
    _ghostPink = std::make_shared<Ghost>(_renderer, 10 * _block, 10 * _block, _block, 0xFCC4D8FF);
    _ghostInk = std::make_shared<Ghost>(_renderer, 10 * _block, 10 * _block, _block, 0x00E8D8FF);
    _ghostClyde = std::make_shared<Ghost>(_renderer, 10 * _block, 10 * _block, _block, 0xFC9838FF);

}

void Ghosts::OnUpdate(const std::vector<std::shared_ptr<Block>> &wallWithDoorGhost, const std::vector<std::shared_ptr<Block>> &door)
{
    _ghostRed->OnUpdate(wallWithDoorGhost);
    _ghostRed->CollisionDoor(door);
    _ghostPink->OnUpdate(wallWithDoorGhost);
    _ghostPink->CollisionDoor(door);
    _ghostInk->OnUpdate(wallWithDoorGhost);
    _ghostInk->CollisionDoor(door);
    _ghostClyde->OnUpdate(wallWithDoorGhost);
    _ghostClyde->CollisionDoor(door);
}
