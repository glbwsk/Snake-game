#include "playingstate.hpp"
#include "menustate.hpp"
#include "snake.hpp"
#include "food.hpp"

#define MAP_HEIGHT      500
#define MAP_WIDTH       920
#define SEG_SIZE        20
#define LENGTH          5

//THESE CONDITIONS SHOULD BE TRUE:
//! (SEG_SIZE)%MAP_WIDTH==(SEG_SIZE)%MAP_HEIGHT==0
//! foodShape radius == SEG_SIZE/2


GameStatePlaying::GameStatePlaying(GameEngine* game)
: snake( MAP_WIDTH, MAP_HEIGHT, SEG_SIZE, SEG_SIZE, LENGTH ), food( MAP_WIDTH, MAP_HEIGHT, SEG_SIZE, SEG_SIZE/2 )
{
    this->game=game;
    timeSinceLastUpdate = 0;
    timePerFrame = 1.0/game->GetFrameLimit();
    if( bgTexture.loadFromFile("textures/bg.jpeg"))
        bgSprite.setTexture(bgTexture);
}

void GameStatePlaying::HandleInput()
{
    if (updated) snake.HandleSnakeInput();

    //conditiion switching GameStatePlaying to GameStateDead
    if ( collision.IsSnakeBodyCollision(snake) )
    {
        //TODO: GameStateDead
        game->ChangeState(new GameStateMenu(game));
    }
}

void GameStatePlaying::Update(const float secElapsed)
{
    timeSinceLastUpdate += secElapsed;
    while(timeSinceLastUpdate > timePerFrame )
    {
        collision.HandleFoodCollision(snake, food);
        snake.UpdateSnake(secElapsed, updated);
        timeSinceLastUpdate -= timePerFrame;
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
        window.draw(bgSprite);
        snake.DrawSnake(window);
        food.DrawFood(window);
        food.DrawScore(window);
    window.display();
}
