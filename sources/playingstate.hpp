#pragma once

#include "gamestate.hpp"
#include "food.hpp"

class GameStatePlaying : public GameState
{
public:

    GameStatePlaying(GameEngine* game);
    ~GameStatePlaying();

    virtual void Draw(sf::RenderWindow &window);
    virtual void Update(const float secElapsed);
    virtual void HandleInput();

private:

    float timeSinceLastUpdate;
    Snake snake;
    Food food;
};
