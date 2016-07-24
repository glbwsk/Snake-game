#include "Game.hpp"
#include "snake.hpp"
#include <iostream>
#include <fstream>

Game::Game()
: window(sf::VideoMode(800, 600), "SNAKE v0.1b")
{
    window.setFramerateLimit(60);
    timePerFrame=sf::seconds(1.0/60.0);
    timeSinceLastUpdate = sf::Time::Zero;
    gameOver=false;
}

Game::~Game()
{
    //
}

void Game::runGame()
{
    sf::Clock clock;
    sf::Time elapsedTime;
    while(!gameOver)
    {
        elapsedTime = clock.restart();
        processInput();
        updateGame(elapsedTime);
        drawGame();
    }

    window.close();
}

void Game::processInput()
{
    snake.input();
}

void Game::updateGame(sf::Time elapsed)
{
    timeSinceLastUpdate += elapsed;
    while(timeSinceLastUpdate > timePerFrame)
    {
        snake.update(elapsed);
        food.handleFoodCollision(snake);
        timeSinceLastUpdate -= timePerFrame;
    }
}

void Game::drawGame()
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

    window.display();
}

