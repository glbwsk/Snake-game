#include "deadstate.hpp"
#include "menustate.hpp"

GameStateDead::GameStateDead(GameEngine* game)
{
    this->game=game;
    timeRunning = 0;
    sf::sleep(sf::seconds(0.5));

    bgTexture.loadFromImage(game->GetWindow()->capture());
    bgSprite.setTexture(bgTexture);

    if(font.loadFromFile("textures/zorque.ttf"))
    {
        textGameOver.setFont(font);
        textGameOver.setColor(sf::Color::White);
        textInfo=textGameOver;

        //title
        textGameOver.setCharacterSize(80);
        textInfo.setCharacterSize(50);

        textGameOver.setString("GAME OVER");
        textInfo.setString("PRESS RMB TO CONTINUE");

        textGameOver.setPosition(game->GetWinWidth()/2-textGameOver.getGlobalBounds().width/2, 20);
        textInfo.setPosition(game->GetWinWidth()/2-textInfo.getGlobalBounds().width/2, 200);
    }
}

void GameStateDead::Draw(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            game->Quit();
    }

    window.clear();

    window.draw(bgSprite);
    window.draw(textGameOver);
    window.draw(textInfo);

    window.display();
}

void GameStateDead::Update(const float secElapsed)
{
    //text animation
    timeRunning += secElapsed;
    if( timeRunning < 0.5 )
    {
        textInfo.setColor(sf::Color::Transparent);
    }
    else if (timeRunning > 0.5 && timeRunning < 1.0 )
    {
        textInfo.setColor(sf::Color::White);
    }
    else timeRunning = 0;
}

void GameStateDead::HandleInput()
{
    if( sf::Mouse::isButtonPressed(sf::Mouse::Right) )
        game->ChangeState(new GameStateMenu(game));
}
