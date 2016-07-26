#include "Game.hpp"
#include "snake.hpp"

GameEngine::GameEngine()
: window(sf::VideoMode(800, 600), "SNAKE v0.1b")
{
    window.setFramerateLimit(60);
    timePerFrame=sf::seconds(1.0/60.0);
    timeSinceLastUpdate = sf::Time::Zero;
    gameRunning=true;
}

GameEngine::~GameEngine()
{
    //
}

void GameEngine::runGame()
{
    sf::Clock clock;
    sf::Time elapsedTime;
    while(gameRunning)
    {
        elapsedTime = clock.restart();
        processInput();
        updateGame(elapsedTime);
        drawGame();
    }

    window.close();
}

void GameEngine::processInput()
{
    snake.input();
}

void GameEngine::updateGame(sf::Time elapsed)
{
    timeSinceLastUpdate += elapsed;
    while(timeSinceLastUpdate > timePerFrame)
    {
        food.handleFoodCollision(snake);
        snake.update(elapsed);
        timeSinceLastUpdate -= timePerFrame;
    }
}

void GameEngine::drawGame()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            gameRunning=false;
    }

    window.clear();

    snake.drawSnake(window);
    food.drawFood(window);

    window.display();
}

