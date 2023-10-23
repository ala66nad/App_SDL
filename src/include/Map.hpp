#pragma once

#include "Block.hpp"
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
    std::vector<std::unique_ptr<Block>> GetWall(SDL_Renderer* renderer, int block);
};
