#pragma once

#include "Entity.hpp"
#include "Block.hpp"
#include <vector>
#include <memory>

class Ghost : public Entity
{
    private:
        

    public:
        Ghost(SDL_Renderer *renderer, int x, int y, int block);
        void OnUpdate(const std::vector<std::shared_ptr<Block>> &b);
        bool OnDraw(uint32_t color);
        bool CollisionWithWall(const std::shared_ptr<Block> &b);
        void CollisionDoor(const std::vector<std::shared_ptr<Block>> &b);
};