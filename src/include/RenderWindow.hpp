#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#define UNHEX(c) ((c >> 8 * 3) & 0xFF), ((c >> 8 * 2) & 0xFF), ((c >> 8 * 1) & 0xFF), ((c >> 8 * 0) & 0xFF)

class RenderWindow
{    
private:
    SDL_Window* _window{nullptr};
    SDL_Renderer* _renderer{nullptr};
    std::string _title;
    int _w, _h;

public:
    RenderWindow(std::string title, int w, int h);
    bool OnInit();
    void OnCleanUp();
    void OnClear();
    void OnDisplay();
    void OnDrawRect(SDL_Rect rectangle, uint32_t color);
    void OnError(std::string s);
};