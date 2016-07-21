#include "Snake.hpp"

Snake::Snake()
{
    speed=10;
    segmentSize=19;
    currDirection=STOP;
    timeSinceLastUpdate = sf::Time::Zero;
    timePerFrame = sf::seconds(1/speed);
    singleSegment.setSize(sf::Vector2f(segmentSize, segmentSize));
    singleSegment.setFillColor(sf::Color(225, 32, 32));
    singleSegment.setPosition(sf::Vector2f(400, 300));
    snakeSegments.push_back(singleSegment);
    singleSegment.setFillColor(sf::Color(250, 250, 50));
    for(int i=0; i<5; i++) snakeSegments.push_back(singleSegment);
}

Snake::~Snake()
{

}

void Snake::drawSnake(sf::RenderWindow &window)
{
    for(const auto& segment : snakeSegments)
            window.draw(segment);
}

void Snake::input()
{
    //WSAD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && currDirection!=DOWN)
    {
        currDirection=UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && currDirection!=UP)
    {
        currDirection=DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currDirection!=RIGHT)
    {
        currDirection=LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && currDirection!=LEFT)
    {
        currDirection=RIGHT;
    }
}

void Snake::update()
{
    timePerFrame = sf::seconds(1/speed);
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    while(timeSinceLastUpdate > timePerFrame)
    {
        switch (currDirection)
        {
        case UP:
            changePosition(0, -segmentSize-1);
            break;
        case DOWN:
            changePosition(0, segmentSize+1);
            break;
        case LEFT:
            changePosition(-segmentSize-1, 0);
            break;
        case RIGHT:
            changePosition(segmentSize+1, 0);
            break;
        case STOP:
            break;
        }
        timeSinceLastUpdate -= timePerFrame;
    }
}

void Snake::changePosition(float x, float y)
{
    sf::RectangleShape newHead = snakeSegments.front();
    snakeSegments.front().setFillColor(sf::Color(250, 250, 50));
    newHead.move(x, y);
    snakeSegments.push_front(newHead);
    snakeSegments.pop_back();
}

void Snake::addSegment(sf::RectangleShape seg)
{
    snakeSegments.push_back(seg);
}

sf::RectangleShape Snake::getSnakesHead()
{
    return snakeSegments.front();
}

void Snake::setspeed(float sp)
{
    speed = sp;
}

float Snake::getspeed()
{
    return speed;
}
