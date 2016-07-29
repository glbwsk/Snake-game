#pragma once

#include "snake.hpp"
#include "food.hpp"

class Collision
{
public:

    Collision()=default;
    ~Collision()=default;

    template<class ObjA, class ObjB>
    bool IsCollision(ObjA objectA, ObjB objectB);

    void HandleFoodCollision(Snake &snake, Food &food);
    bool IsSnakeBodyCollision(Snake snake);

private:

    sf::FloatRect boxA, boxB;

};
