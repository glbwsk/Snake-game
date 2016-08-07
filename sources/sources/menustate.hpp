#pragma once

#include "gamestate.hpp"

class GameStateMenu : public GameState
{
public:

    GameStateMenu(GameEngine* game);
    ~GameStateMenu()=default;

    virtual void Draw(sf::RenderWindow &window) override;
    virtual void Update(const float secElapsed) override;
    virtual void HandleInput() override;

private:

    float timeSinceLastUpdate;

    sf::Sprite bgSprite;
    sf::Texture bgTexture;
    sf::Font font;
    sf::Text text[3];

};
