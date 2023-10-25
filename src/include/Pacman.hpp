#pragma once

#include "Entity.hpp"
#include "Block.hpp"
#include <vector>
#include <memory>

class Pacman : public Entity
{
    private:
        int _x{0}, _y{0}, _block{0};
        int _vx{0}, _vy{0}, _velocity{4};

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
        void ControlKey();
};