#include "Snake.hpp"

Snake::Snake(int mapWidth, int mapHeight)
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;

    //speed parameters
    currDirection = Direction::STOP;
    speed = 15;
    segmentSize = 19.0;
    timeSinceSnakeUpdate = 0.0;

    //setting first segment
    singleSegment.setSize( sf::Vector2f(segmentSize, segmentSize) );
    singleSegment.setFillColor( sf::Color(225, 32, 32) );
    singleSegment.setPosition( sf::Vector2f(400, 300) );
    AddSegment(singleSegment);

    //additional segments in different color
    singleSegment.setFillColor( sf::Color(250, 250, 50) );
    for(int i=0; i<5; i++)
        AddSegment(singleSegment);
}

Snake::~Snake()
{
    //
}

void Snake::DrawSnake(sf::RenderWindow &window)
{
    for(const auto& segment : snakeSegments)
            window.draw(segment);
}

void Snake::HandleSnakeInput()
{
    //WSAD
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && currDirection!=Direction::DOWN)
    {
        currDirection=Direction::UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && currDirection!=Direction::UP)
    {
        currDirection=Direction::DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currDirection!=Direction::RIGHT)
    {
        currDirection=Direction::LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && currDirection!=Direction::LEFT)
    {
        currDirection=Direction::RIGHT;
    }
}

void Snake::UpdateSnake(const float secElapsed)
{
    float speedParam = 1.0/speed;
    timeSinceSnakeUpdate += secElapsed;

    while(timeSinceSnakeUpdate > speedParam)
    {
        switch (currDirection)
        {
        case Direction::UP:
            ChangePosition(0, -segmentSize-1);
            break;
        case Direction::DOWN:
            ChangePosition(0, segmentSize+1);
            break;
        case Direction::LEFT:
            ChangePosition(-segmentSize-1, 0);
            break;
        case Direction::RIGHT:
            ChangePosition(segmentSize+1, 0);
            break;
        case Direction::STOP:
            break;
        }
        timeSinceSnakeUpdate -= speedParam;
    }
}

void Snake::ChangePosition(float x, float y)
{
    sf::RectangleShape newHead = snakeSegments.front();

    sf::Vector2f currPositon=newHead.getPosition();
    currPositon.x = FloatMod(currPositon.x+x, mapWidth);
    currPositon.y = FloatMod(currPositon.y+y, mapHeight);

    snakeSegments.front().setFillColor(sf::Color(250, 250, 50));
    newHead.setPosition(currPositon);

    snakeSegments.push_front(newHead);
    snakeSegments.pop_back();
}

void Snake::AddSegment(sf::RectangleShape seg)
{
    snakeSegments.push_back(seg);
}

sf::RectangleShape Snake::GetSnakesHead()
{
    return snakeSegments.front();
}

float Snake::FloatMod(float num, float modulo)
{
    if( num >= modulo ) return num-modulo;
    else if (num < 0 ) return modulo;
    else return num;
}
