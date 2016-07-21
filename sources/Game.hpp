#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "item.hpp"

class Game
{
public:
    int windowWidth;
    int windowHeight;

    Game();
    ~Game();
    void runGame();
    void draw();

private:
    bool gameOver;
    sf::RenderWindow window;
    Snake snake;
    Food food;
};

#endif // _GAME_HPP_
