#pragma once

#include "gamestate.hpp"

class GameStateDead : public GameState
{
public:

    GameStateDead(GameEngine* game);
    ~GameStateDead()=default;

    virtual void Draw(sf::RenderWindow &window) override;
    virtual void Update(const float secElapsed) override;
    virtual void HandleInput() override;

private:

    sf::Font font;
    sf::Text textGameOver, textInfo;
    bool keyPressed;
    float timeRunning;
    sf::Texture bgTexture;
    sf::Sprite bgSprite;
};
