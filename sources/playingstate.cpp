#include "playingstate.hpp"
#include "snake.hpp"
#include "food.hpp"

GameStatePlaying::GameStatePlaying(GameEngine* game)
: snake(960, 540), food(960, 540, 20)
{
    timeSinceLastUpdate=0;
    this->game=game;
}

void GameStatePlaying::HandleInput()
{
    snake.HandleSnakeInput();
}

void GameStatePlaying::Update(const float secElapsed)
{
    timeSinceLastUpdate += secElapsed;
    while(timeSinceLastUpdate > 1.0/60)
    {
        food.HandleCollision(snake);
        snake.UpdateSnake(secElapsed);
        timeSinceLastUpdate -= 1.0/60;
    }
}

void GameStatePlaying::Draw(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            game->Quit();
    }

    window.clear();

    snake.DrawSnake(window);
    food.DrawFood(window);

    window.display();
}
