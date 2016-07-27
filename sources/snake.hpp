#pragma once

#include <SFML/Graphics.hpp>
#include <list>

enum class Direction
{
    STOP, LEFT, RIGHT, UP, DOWN
};

class Snake
{
public:

    Snake(int mapWidth, int mapHeight);
    ~Snake();

    //main methods
    void DrawSnake(sf::RenderWindow &window);
    void HandleSnakeInput();
    void UpdateSnake(const float secElapsed);
    void ChangePosition(float x, float y);

    //setters & getters
    void SetSpeed(float speed) { this->speed=speed; }
    float GetSpeed() { return speed; }
    void AddSegment(sf::RectangleShape seg);
    sf::RectangleShape GetSnakesHead();

    //utils
    float FloatMod(float num, float modulo);

private:

    //body
    std::list<sf::RectangleShape> snakeSegments;
    sf::RectangleShape singleSegment;
    float segmentSize;

    //movement
    Direction currDirection;
    float speed;
    float timeSinceSnakeUpdate;
    int mapWidth, mapHeight;
};

