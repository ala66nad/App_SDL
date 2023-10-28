#pragma once

#include "Entity.hpp"
#include "Block.hpp"
#include "Dot.hpp"
#include "PowerDot.hpp"
#include <vector>
#include <memory>

class Pacman : public Entity
{
    private:

    public:
        int LastKey{5};

    public:
        Pacman(SDL_Renderer* renderer, int x, int y, int block);
        bool OnDraw();
        void OnUpdate(const std::vector<std::shared_ptr<Block>> &b);
        bool CollisionWithWall(const std::shared_ptr<Block> &b);
        void ControlCollision(const std::vector<std::shared_ptr<Block>> &b);
        void ControlCollisionVH(const std::vector<std::shared_ptr<Block>> &b);
        void CollisionDoor(const std::vector<std::shared_ptr<Block>> &b);
        bool CollisionWithDot(const std::shared_ptr<Dot> &b);
        void CollisionDot(const std::vector<std::shared_ptr<Dot>> &b);
        bool CollisionWithPowerDot(const std::shared_ptr<PowerDot> &b);
        void CollisionPowerDot(const std::vector<std::shared_ptr<PowerDot>> &b);
        void ControlKey();
};