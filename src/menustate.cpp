#include "menustate.hpp"
#include "playingstate.hpp"
#include "SFML/Graphics.hpp"

GameStateMenu::GameStateMenu(GameEngine* game)
{
    this->game=game;
    textCount = 3;

    mousePositon.x = 0;
    mousePositon.y = 0;

    if(font.loadFromFile("textures/zorque.ttf"))
    {
        text.setFont(font);

        //title
        text.setCharacterSize(80);
        text.setColor(sf::Color::Green);
        text.setString("SNAKE-GAME");
        text.setPosition(game->GetWinWidth()/2-text.getGlobalBounds().width/2, 20);
        textArr.push_back(text);

        //other menu positons
        std::string str[] = { "START", "EXIT" };
        text.setCharacterSize(60);
        text.setColor(sf::Color::White);

        for(int i=0; i<textCount-1; i++)
        {
            text.setString(str[i]);
            text.setPosition(game->GetWinWidth()/2-text.getGlobalBounds().width/2, 200+i*100);
            textArr.push_back(text);
        }
    }
}

void GameStateMenu::Draw(sf::RenderWindow &window)
{
    mousePositon = sf::Mouse::getPosition(window);

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            game->Quit();
    }

    window.clear();

    for(int i=0; i<textCount; i++)
        window.draw(textArr[i]);

    window.display();
}

void GameStateMenu::Update(const float secElapsed)
{
    for(int i=1; i<textCount; i++)
    {
        if(textArr[i].getGlobalBounds().contains(mousePositon.x, mousePositon.y))
            textArr[i].setColor(sf::Color::Blue);
        else
            textArr[i].setColor(sf::Color::White);
    }
}

void GameStateMenu::HandleInput()
{
    if( textArr[1].getColor() == sf::Color::Blue && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
        game->ChangeState(new GameStatePlaying(game));
    else if( textArr[2].getColor() == sf::Color::Blue && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
        game->Quit();
    else return;
}

