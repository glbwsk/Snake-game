#include "food.hpp"
#include <sstream>
#include <fstream>

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
    bestScore = ReadBestScore();

    if(font.loadFromFile("textures/zorque.ttf"))
    {
        scoreText.setFont(font);
        scoreText.setCharacterSize(30);
        scoreText.setStyle(sf::Text::Bold);
        scoreText.setColor(sf::Color::White);
        bestScoreText=scoreText;

        //set these to fit the game window
        scoreText.setPosition(mapBorder, mapHeight+mapBorder);
        bestScoreText.setPosition(mapWidth-245, mapHeight+mapBorder);
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
    std::ostringstream ss1, ss2;

    ss1<<"Score: "<<score;
    scoreText.setString(ss1.str());
    window.draw(scoreText);

    ss2<<"Best Score: "<<bestScore;
    bestScoreText.setString(ss2.str());
    window.draw(bestScoreText);
}

int Food::ReadBestScore()
{
    std::ifstream file("data/score");

    if(file.is_open())
    {
        file>>bestScore;
        file.close();
    }
    else bestScore=0;

    return bestScore;
}

bool Food::SetBestScore()
{
    std::ofstream file("data/score");

    if(file.is_open())
    {
        if(bestScore < score)
        {
            bestScore=score;
            file<<bestScore;
            file.close();
            return true;
        }
        else
        {
            file<<bestScore;
            file.close();
        }
    }

    return false;
}


