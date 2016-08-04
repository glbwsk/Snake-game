#include "food.hpp"
#include <sstream>

Food::Food(int mapWidth, int mapHeight, int mapBorder, int radius )
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    this->mapBorder=mapBorder;
    this->radius=radius;

    foodShape.setRadius( radius );
    foodShape.setPointCount	(4);

    foodShape.setFillColor( sf::Color(200, 255, 150) );
    SetRandomizedPosition();
    score = 0;

    if(font.loadFromFile("textures/zorque.ttf"))
    {
        text.setFont(font);
        text.setCharacterSize(30);
        text.setStyle(sf::Text::Bold);
        text.setColor(sf::Color::White);
        text.setPosition(20,525);
    }
}

void Food::DrawFood(sf::RenderWindow &window)
{
    window.draw(foodShape);
}

void Food::SetRandomizedPosition()
{
    //2*radius should be equal to snake's segment size
    int x = rand()%( (mapWidth) / (2*radius) ) * 2*radius + mapBorder;
    int y = rand()%( (mapHeight) / (2*radius) ) * 2*radius + mapBorder;
    foodShape.setPosition(sf::Vector2f(x, y));
}

void Food::DrawScore(sf::RenderWindow &window)
{
    std::ostringstream ss;
    ss<<"Score: "<<score;

    text.setString(ss.str());
    window.draw(text);
}

