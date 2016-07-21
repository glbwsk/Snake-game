#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <SFML/Graphics.hpp>
#include "snake.hpp"

class Food
{
public:
    Food();
    ~Food();

    bool collision(sf::RectangleShape snakesHead);
    void drawFood(sf::RenderWindow &window);
    void setRandomizedPosition();
    void handleFoodCollision(Snake &snake);

private:
    sf::CircleShape foodItem;
    unsigned int x;
    unsigned int y;
    float speed;
};

#endif
