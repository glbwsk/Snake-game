#include "food.hpp"

Food::Food(int mapWidth, int mapHeight, int step)
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    this->step=step;

    radius=10;
    foodShape.setRadius( radius );
    foodShape.setFillColor( sf::Color(0, 111, 250) );
    SetRandomizedPosition();
}

Food::~Food()
{

}

bool Food::Collision(sf::RectangleShape snakesHead)
{
    sf::FloatRect foodBox = foodShape.getGlobalBounds();
    sf::FloatRect snakesHeadBox = snakesHead.getGlobalBounds();

    if( snakesHeadBox.intersects( foodBox ) ) return true;
    else return false;
}

void Food::DrawFood(sf::RenderWindow &window)
{
    window.draw(foodShape);
}

void Food::SetRandomizedPosition()
{
    int x = rand()%( (mapWidth-radius) / step ) * step;
    int y = rand()%( (mapHeight-radius) / step ) * step;
    foodShape.setPosition(sf::Vector2f(x, y));
}

void Food::HandleCollision(Snake &snake)
{
    sf::RectangleShape head = snake.GetSnakesHead();
    if( Collision( head ) )
    {
        snake.AddSegment(head);
        SetRandomizedPosition();
        snake.SetSpeed(snake.GetSpeed()+0.5);
    }
}
