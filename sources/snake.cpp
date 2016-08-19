#include "Snake.hpp"

Snake::Snake(int mapWidth, int mapHeight, int mapBorder, int segmentSize, int initLength)
{
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
    this->mapBorder=mapBorder;
    this->segmentSize=segmentSize;
    this->initLength=initLength;

    //speed parameters
    currDirection = Direction::STOP;
    speed = 10;
    timeSinceSnakeUpdate = 0.0;

    //setting first segment
    singleSegment.setSize( sf::Vector2f(segmentSize-1, segmentSize-1) );
    singleSegment.setFillColor( sf::Color(225, 100, 32) );
    singleSegment.setPosition( sf::Vector2f(mapWidth/2, mapHeight/2+10) );
    AddSegment(singleSegment);

    //additional starting segments are in different color
    singleSegment.setFillColor( sf::Color(250, 250, 50) );
    for(int i=0; i<initLength-1; i++)
    {
        singleSegment.move(0, segmentSize);
        AddSegment(singleSegment);
    }
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

void Snake::UpdateSnake(const float secElapsed, bool &updated)
{
    float speedParam = 1.0/speed;
    timeSinceSnakeUpdate += secElapsed;
    updated = false;

    while(timeSinceSnakeUpdate > speedParam)
    {
        switch (currDirection)
        {
        case Direction::UP:
            ChangePosition(0, -segmentSize);
            break;
        case Direction::DOWN:
            ChangePosition(0, segmentSize);
            break;
        case Direction::LEFT:
            ChangePosition(-segmentSize, 0);
            break;
        case Direction::RIGHT:
            ChangePosition(segmentSize, 0);
            break;
        case Direction::STOP:
            break;
        }
        timeSinceSnakeUpdate -= speedParam;
        updated = true;
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

float Snake::FloatMod(float num, float modulo)
{
    if( num >= modulo+mapBorder ) return mapBorder;
    else if( num < mapBorder ) return modulo;
    else return num;
}

sf::RectangleShape Snake::GetSnakesSegment(unsigned int N)
{
    auto segIterator = snakeSegments.begin();
    if (snakeSegments.size() > N)
    {
        std::advance(segIterator, N);
    }
    return *segIterator;
}

void Snake::AddSegment(sf::RectangleShape seg)
{
    snakeSegments.push_back(seg);
}

int Snake::GetSnakeLength()
{
    return snakeSegments.size();
}
