#pragma once

#include <SFML/Graphics.hpp>
#include "snake.hpp"

class Food
{
public:

    Food(int mapWidth, int mapHeight, int step);
    ~Food()=default;

    //methods for drawing
    void DrawFood(sf::RenderWindow &window);
    void SetRandomizedPosition();

    //setters & getters
    sf::CircleShape GetFoodShape() { return foodShape; };

private:

    sf::CircleShape foodShape;
    int radius;

    //map resolution
    //step is sigle snake move (segment+1)
    int mapWidth, mapHeight, step;
};

