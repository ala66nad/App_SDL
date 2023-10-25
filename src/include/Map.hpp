#pragma once

#include "Block.hpp"
#include "Dot.hpp"
#include "PowerDot.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Map
{
private:
    std::vector<std::string> _map{};
    std::vector<std::shared_ptr<Block>> GetBlock(SDL_Renderer *renderer, int block, char, uint32_t color);

public:
    Map();
    std::vector<std::shared_ptr<Block>> GetDoor(SDL_Renderer *renderer, int block);
    std::vector<std::shared_ptr<Block>> GetWall(SDL_Renderer *renderer, int block);
    std::vector<std::shared_ptr<Block>> GetZero(SDL_Renderer *renderer, int block);
    std::vector<std::shared_ptr<Dot>> GetDot(SDL_Renderer *renderer, int block, int scale);
    std::vector<std::shared_ptr<PowerDot>> GetPowerDot(SDL_Renderer *renderer, int block, int scale);
};
