#pragma once

#include "gamestate.hpp"
#include "food.hpp"
#include "collision.hpp"

class GameStatePlaying : public GameState
{
public:

    GameStatePlaying(GameEngine* game);
    ~GameStatePlaying()=default;

    virtual void Draw(sf::RenderWindow &window) override;
    virtual void Update(const float secElapsed) override;
    virtual void HandleInput() override;

private:

    float timeSinceLastUpdate;
    bool updated;
    Snake snake;
    Food food;
    Collision collision;

    sf::Sprite bgSprite;
    sf::Texture bgTexture;
};
