#pragma once

#include "Entity.hpp"
#include "Block.hpp"
#include <vector>
#include <memory>
#include <random>

class Ghost : public Entity
{
    private:
        int lastVx{0}, lastVy{0};

    public:    
        Ghost(SDL_Renderer *renderer, int x, int y, int block, uint32_t color);
        void OnUpdate(const std::vector<std::shared_ptr<Block>> &b);
        void Avance(int v);
        bool CollisionWithWall(const std::shared_ptr<Block> &b);
        void ControlCollision(const std::vector<std::shared_ptr<Block>> &bg);
        void CollisionDoor(const std::vector<std::shared_ptr<Block>> &b);
        bool Direction(int x, int y, const std::vector<std::shared_ptr<Block>> bg);
        std::vector<int> ControlDirection(const std::vector<std::shared_ptr<Block>> b);
        double GenereSens(int min, int max);
};