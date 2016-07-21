#include "Game.hpp"
#include "snake.hpp"

Game::Game()
: window(sf::VideoMode(800, 600), "SNAKE v0.1b")
{
    window.setFramerateLimit(60);
    windowWidth=800;
    windowHeight=600;
    gameOver=false;
}

Game::~Game()
{
    //
}

void Game::runGame()
{
    while(!gameOver)
        draw();

    window.close();
}

void Game::draw()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gameOver=true;
    }

    window.clear();
        snake.drawSnake(window);
        food.drawFood(window);
        snake.input();
        snake.update();
        food.handleFoodCollision(snake);


    window.display();
}

