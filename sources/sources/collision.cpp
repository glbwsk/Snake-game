#include "collision.hpp"
#include <SFML/Graphics.hpp>

Collision::Collision()
{
    if( buffer1.loadFromFile("sounds/gameover.wav") )
        gameOverSound.setBuffer(buffer1);

    if( buffer2.loadFromFile("sounds/eat.wav") )
        eatSound.setBuffer(buffer2);
}

template<class ObjA, class ObjB>
bool Collision::IsCollision(ObjA objectA, ObjB objectB)
{
    sf::FloatRect boxA = objectA.getGlobalBounds();
    sf::FloatRect boxB = objectB.getGlobalBounds();

    if( boxA.intersects( boxB ) ) return true;
    else return false;
}

void Collision::HandleFoodCollision(Snake &snake, Food &food)
{
    sf::RectangleShape head = snake.GetSnakesSegment(0);

    if( IsCollision( head, food.GetFoodShape() ) )
    {
        eatSound.play();
        snake.SetSpeed(snake.GetSpeed()+0.5);
        snake.AddSegment(snake.GetSnakesSegment(1));
        food.incrementScore();
    }

    while( IsCollision( head, food.GetFoodShape() ) )
        food.SetRandomizedPosition();
}

bool Collision::IsSnakeBodyCollision(Snake snake)
{
    sf::RectangleShape head = snake.GetSnakesSegment(0);
    for(int i=2; i<snake.GetSnakeLength(); ++i)
    {
        if( IsCollision( head, snake.GetSnakesSegment(i) ) )
        {
            gameOverSound.play();
            sf::sleep(sf::seconds(0.5));
            return true;
        }
    }
    return false;
}

