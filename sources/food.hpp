#pragma once

#include <SFML/Graphics.hpp>
#include "snake.hpp"

class Food
{
public:

    Food(int mapWidth, int mapHeight, int step);
    ~Food();

    //methods for collisons
    void HandleCollision(Snake &snake);
    bool Collision(sf::RectangleShape snakesHead);

    //methods for drawing
    void DrawFood(sf::RenderWindow &window);
    void SetRandomizedPosition();

private:

    sf::CircleShape foodShape;
    int radius;

    int mapWidth, mapHeight, step;
};

