#ifndef __EVENT__
#define __EVENT__

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Event
{
    public:
        Event();
        virtual ~Event();
        virtual void OnEvent(SDL_Event *Event);
        virtual void OnExit();
        virtual void OnKeyDown(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode);
        virtual void OnKeyUp(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode);
        virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
        virtual void OnLButtonDown(int mX, int mY);
        virtual void OnLButtonUp(int mX, int mY);
        virtual void OnRButtonDown(int mX, int mY);
        virtual void OnRButtonUp(int mX, int mY);
        virtual void OnMButtonDown(int mX, int mY);
        virtual void OnMButtonUp(int mX, int mY);
};

#endif