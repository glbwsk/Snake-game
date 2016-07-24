#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "item.hpp"

class Game
{
public:

    Game();
    ~Game();
    void runGame();
    void processInput();
    void updateGame(sf::Time elapsed);
    void drawGame();

private:
    sf::Time timePerFrame;
    sf::Time timeSinceLastUpdate;
    sf::RenderWindow window;
    Snake snake;
    Food food;
    bool gameOver;
};

#endif // _GAME_HPP_
