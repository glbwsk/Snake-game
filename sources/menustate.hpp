#pragma once

#include "gamestate.hpp"
#include <vector>

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
    int textCount;

    sf::Font font;
    std::vector<sf::Text> textArr;
    sf::Text text;
    sf::Vector2i mousePositon;
};
