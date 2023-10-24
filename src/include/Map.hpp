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
public:
    Map();
    std::vector<std::unique_ptr<Block>> GetDoor(SDL_Renderer* renderer, int block);
    std::vector<std::unique_ptr<Block>> GetWall(SDL_Renderer* renderer, int block);
    std::vector<std::unique_ptr<Block>> GetZero(SDL_Renderer* renderer, int block);
    std::vector<std::unique_ptr<Dot>> GetDot(SDL_Renderer* renderer, int block, int scale);
    std::vector<std::unique_ptr<PowerDot>> GetPowerDot(SDL_Renderer* renderer, int block, int scale);
};
