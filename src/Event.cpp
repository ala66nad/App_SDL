#include "Event.hpp"

Event::Event(){}

Event::~Event(){}

void Event::OnEvent(SDL_Event *Event)
{
    switch (Event->type)
    {

    case SDL_MOUSEMOTION:
    {
        OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
        break;
    }

    case SDL_MOUSEBUTTONDOWN:
    {
        switch (Event->button.button)
        {
        case SDL_BUTTON_LEFT:
        {
            OnLButtonDown(Event->button.x, Event->button.y);
            break;
        }
        case SDL_BUTTON_RIGHT:
        {
            OnRButtonDown(Event->button.x, Event->button.y);
            break;
        }
        case SDL_BUTTON_MIDDLE:
        {
            OnMButtonDown(Event->button.x, Event->button.y);
            break;
        }
        }
        break;
    }

    case SDL_MOUSEBUTTONUP:
    {
        switch (Event->button.button)
        {
        case SDL_BUTTON_LEFT:
        {
            OnLButtonUp(Event->button.x, Event->button.y);
            break;
        }
        case SDL_BUTTON_RIGHT:
        {
            OnRButtonUp(Event->button.x, Event->button.y);
            break;
        }
        case SDL_BUTTON_MIDDLE:
        {
            OnMButtonUp(Event->button.x, Event->button.y);
            break;
        }
        }
        break;
    }
    case SDL_KEYDOWN:
    {
        OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.scancode);
        break;
    }

    case SDL_KEYUP:
    {
        OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.scancode);
        break;
    }

    case SDL_QUIT:
        OnExit();        
        break;

    default:
        break;
    }
}

void Event::OnExit()
{
    // Pure virtual, do nothing
}

void Event::OnKeyDown(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode)
{
    // Pure virtual, do nothing
}

void Event::OnKeyUp(SDL_Keycode sym, SDL_Keycode mod, SDL_Keycode scancode)
{
    // Pure virtual, do nothing
}

void Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{
    // Pure virtual, do nothing
}

void Event::OnLButtonDown(int mX, int mY)
{
    // Pure virtual, do nothing
}

void Event::OnLButtonUp(int mX, int mY)
{
    // Pure virtual, do nothing
}

void Event::OnRButtonDown(int mX, int mY)
{
    // Pure virtual, do nothing
}

void Event::OnRButtonUp(int mX, int mY)
{
    // Pure virtual, do nothing
}

void Event::OnMButtonDown(int mX, int mY)
{
    // Pure virtual, do nothing
}

void Event::OnMButtonUp(int mX, int mY)
{
    // Pure virtual, do nothing
}