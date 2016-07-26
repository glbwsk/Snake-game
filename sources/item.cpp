#include "item.hpp"

Food::Food()
{
    setRandomizedPosition();
    foodItem.setRadius(10);
    foodItem.setFillColor(sf::Color(0, 111, 250));
}

Food::~Food()
{
    //
}

bool Food::collision(sf::RectangleShape snakesHead)
{
    sf::FloatRect foodBox = foodItem.getGlobalBounds();
    sf::FloatRect snakesHeadBox = snakesHead.getGlobalBounds();

    if(snakesHeadBox.intersects(foodBox)) return true;
    else return false;
}

void Food::drawFood(sf::RenderWindow &window)
{
    window.draw(foodItem);
}

void Food::setRandomizedPosition()
{
    srand(time(NULL));
    x = rand()%790;
    y = rand()%590;
    foodItem.setPosition(sf::Vector2f(x, y));
}

void Food::handleFoodCollision(Snake &snake)
{
    sf::RectangleShape head = snake.getSnakesHead();
    if( collision( head ) )
    {
        for(int i=0; i<2; i++) snake.addSegment(head);
        setRandomizedPosition();
        speed=snake.getspeed();
        speed++;
        snake.setspeed(speed);
    }
}
