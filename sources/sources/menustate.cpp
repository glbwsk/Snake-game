#include "menustate.hpp"

#define MAP_HEIGHT      500
#define MAP_WIDTH       920
#define TIME_PER_FRAME  1.0/60

GameStateMenu::GameStateMenu(GameEngine* game)

{
    this->game=game;
    timeSinceLastUpdate=0;
    if( bgTexture.loadFromFile("textures/bgMenu.jpeg"))
        bgSprite.setTexture(bgTexture);

    if(font.loadFromFile("textures/zorque.ttf"))
    {
        text[0].setFont(font);
        text[0].setCharacterSize(60);
        text[0].setColor(sf::Color::White);
        text[2]=text[1]=text[0];

        //set these to fit the menu window
        text[0].setPosition(game->GetWinWidth()/2-200, game->GetWinHeight()/2 - 200);
        text[0].setString("SNAKE-GAME");

        text[1].setPosition(game->GetWinWidth()/2-100, game->GetWinHeight()/2 - 100);
        text[1].setString("START");

        text[2].setPosition(game->GetWinWidth()/2-80, game->GetWinHeight()/2 - 10);
        text[2].setString("EXIT");

        //todo
    }
}

void GameStateMenu::Draw(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            game->Quit();
    }

    window.clear();
        for(int i=0; i<3; i++)
            window.draw(text[i]);
    window.display();
}

void GameStateMenu::Update(const float secElapsed)
{
    //
}

void GameStateMenu::HandleInput()
{
    //
}

