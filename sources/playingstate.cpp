#include "playingstate.hpp"
#include "snake.hpp"
#include "food.hpp"

#define MAP_WIDTH 540
#define MAP_HEIGHT 960
#define TIME_PER_FRAME 1.0/60
#define SEG_SIZE 19

//THESE CONDITIONS SHOULD BE TRUE:
//! (SEG_SIZE+1)%MAP_WIDTH==(SEG_SIZE+1)%MAP_HEIGHT==0
//! foodShape radius == (SEG_SIZE+1)/2

GameStatePlaying::GameStatePlaying(GameEngine* game)
: snake( MAP_HEIGHT, MAP_WIDTH, SEG_SIZE, 5 ), food( MAP_HEIGHT, MAP_WIDTH, 10 )
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
    while(timeSinceLastUpdate > TIME_PER_FRAME)
    {
        //conditiion switching GameStatePlaying to GameStateDead
        if ( collision.IsSnakeBodyCollision(snake) )
        {
            //TODO: GameStateDead
            game->PushState(new GameStatePlaying(game));
        }

        collision.HandleFoodCollision(snake, food);
        snake.UpdateSnake(secElapsed);
        timeSinceLastUpdate -= TIME_PER_FRAME;
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
