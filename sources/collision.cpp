#include "collision.hpp"
#include <SFML/Graphics.hpp>
#include <list>

template<class ObjA, class ObjB>
bool Collision::IsCollision(ObjA objectA, ObjB objectB)
{
    boxA = objectA.getGlobalBounds();
    boxB = objectB.getGlobalBounds();

    if( boxA.intersects( boxB ) ) return true;
    else return false;
}

void Collision::HandleFoodCollision(Snake &snake, Food &food)
{
    sf::RectangleShape head = snake.GetSnakesSegment(0);

    if ( IsCollision( head, food.GetFoodShape() ) )
    {
        snake.SetSpeed(snake.GetSpeed()+0.5);
        snake.AddSegment(snake.GetSnakesSegment(1));
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
            return true;
    }
    return false;
}

