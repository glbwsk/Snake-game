#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "item.hpp"
#include "GameState.hpp"
#include <vector>

class GameEngine
{
public:

    GameEngine();
    ~GameEngine();

    void changeState(GameState* state);
    void pushState(GameState* state);
    void popState();

    void runGame();
    void processInput();
    void updateGame(sf::Time elapsed);
    void drawGame();

    bool running() { return gameRunning; }
    void quit() { gameRunning = false; }

private:
    sf::Time timePerFrame;
    sf::Time timeSinceLastUpdate;
    sf::RenderWindow window;
    Snake snake;
    Food food;
    bool gameRunning;
    std::vector<GameState*> states;
};

#endif // _GAME_HPP_
