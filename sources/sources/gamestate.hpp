#pragma once

#include "gameengine.hpp"

class GameState
{
public:

    virtual ~GameState() = default;
    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual void Update(const float secElapsed) = 0;
    virtual void HandleInput() = 0;

protected:

    GameEngine* game;
};


