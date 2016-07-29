#include "food.hpp"

Food::Food(int mapWidth, int mapHeight, int radius)
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    this->radius=radius;

    foodShape.setRadius( radius );
    foodShape.setFillColor( sf::Color(0, 111, 250) );
    SetRandomizedPosition();
}

void Food::DrawFood(sf::RenderWindow &window)
{
    window.draw(foodShape);
}

void Food::SetRandomizedPosition()
{
    int x = rand()%( (mapWidth) / (2*radius) ) * 2*radius;
    int y = rand()%( (mapHeight) / (2*radius) ) * 2*radius;
    foodShape.setPosition(sf::Vector2f(x, y));
}

