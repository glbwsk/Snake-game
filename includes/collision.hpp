#pragma once

#include <SFML/Audio.hpp>
#include "snake.hpp"
#include "food.hpp"

class Collision
{
public:

    Collision();
    ~Collision()=default;

    template<class ObjA, class ObjB>
    bool IsCollision(ObjA objectA, ObjB objectB);

    void HandleFoodCollision(Snake &snake, Food &food);
    bool IsSnakeBodyCollision(Snake snake, Food food);

private:

    sf::Sound eatSound, gameOverSound;
    sf::SoundBuffer buffer1, buffer2;

};
