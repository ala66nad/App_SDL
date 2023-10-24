#include "Map.hpp"

//----------------------------------------------------------------------
Map::Map()
{
        _map = {
        "111111111111111111111",
        "122222222212222222221",
        "121112111212111211121",
        "131012101212101210131",
        "121112111212111211121",
        "122222222222222222221",
        "121112121111121211121",
        "121112121111121211121",
        "122222122212221222221",
        "111112111010111211111",
        "0000121000b0001210000",
        "000012101141101210000",
        "111112101i0c101211111",
        "5000020010p0100200005",
        "111112101111101211111",
        "000012100000001210000",
        "000012101111101210000",
        "111112101111101211111",
        "122222222212222222221",
        "121112111212111211121",
        "132212222292222212231",
        "111212121111121212111",
        "111212121111121212111",
        "122222122212221222221",
        "121111111212111111121",
        "122222222222222222221",
        "111111111111111111111"};
}

//----------------------------------------------------------------------
std::vector<std::unique_ptr<Block>> Map::GetDoor(SDL_Renderer* renderer, int block)
{
    std::vector<std::unique_ptr<Block>> door;
    door.push_back(std::make_unique<Block>(renderer, 0 * block, 13 * block, block, 0x99FF99F88));
    door.push_back(std::make_unique<Block>(renderer, 20 * block, 13 * block, block, 0x99FF9988));
    return door;
}

//----------------------------------------------------------------------
std::vector<std::shared_ptr<Block>> Map::GetWall(SDL_Renderer *renderer, int block)
{
    std::vector<std::shared_ptr<Block>> bg;
    for (size_t y{0}; y < _map.size(); y++)
    {
        for (size_t x{0}; x < _map[y].size(); x++)
        {
            if (_map[y][x] == '1')
            {
                bg.push_back(std::make_shared<Block>(renderer, x * block, y * block, block, 0xFF88EE77));
            }
        }
    }
    return bg;
}

//----------------------------------------------------------------------
std::vector<std::unique_ptr<Block>> Map::GetZero(SDL_Renderer* renderer, int block)
{    
    std::vector<std::unique_ptr<Block>> bg;
    for (size_t y{0}; y < _map.size(); y++)
    {
        for (size_t x{0}; x < _map[y].size(); x++)
        {
            if (_map[y][x] == '0')
            {
                bg.push_back(std::make_unique<Block>(renderer, x * block, y * block, block, 0xFF444477));
            }
        }
    }
    return bg;
}

//----------------------------------------------------------------------
std::vector<std::unique_ptr<Dot>> Map::GetDot(SDL_Renderer* renderer, int block, int scale)
{    
    std::vector<std::unique_ptr<Dot>> bg;
    for (size_t y{0}; y < _map.size(); y++)
    {
        for (size_t x{0}; x < _map[y].size(); x++)
        {
            if (_map[y][x] == '2')
            {
                bg.push_back(std::make_unique<Dot>(renderer, x * block, y * block, block, scale));
            }
        }
    }
    return bg;
}

//----------------------------------------------------------------------
std::vector<std::unique_ptr<PowerDot>> Map::GetPowerDot(SDL_Renderer* renderer, int block, int scale)
{    
    std::vector<std::unique_ptr<PowerDot>> bg;
    for (size_t y{0}; y < _map.size(); y++)
    {
        for (size_t x{0}; x < _map[y].size(); x++)
        {
            if (_map[y][x] == '3')
            {
                bg.push_back(std::make_unique<PowerDot>(renderer, x * block, y * block, block, scale));
            }
        }
    }
    return bg;
}
//----------------------------------------------------------------------