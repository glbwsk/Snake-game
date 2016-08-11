#include <stack>

#include <SFML/Graphics.hpp>

#include "gameengine.hpp"
#include "gamestate.hpp"

GameEngine::GameEngine()
{
    winWidth = 960;
    winHeight = 560;
    maxFrames = 60;
    window.create(sf::VideoMode(winWidth, winHeight), "SNAKE", sf::Style::Close);
    window.setFramerateLimit(maxFrames);
    gameRunning=true;
    srand(time(NULL));
}

GameEngine::~GameEngine()
{
    while(!states.empty())
        PopState();
}

void GameEngine::GameLoop()
{
    srand(time(NULL));

    sf::Clock clock;
    sf::Time elapsed;
    float time;

    while(gameRunning)
    {
        if(PeekState() == nullptr)
        {
            gameRunning=false;
            break;
        }

        elapsed = clock.restart();
        time = elapsed.asSeconds();

        PeekState()->HandleInput();
        PeekState()->Update(time);
        PeekState()->Draw(window);
    }
}

void GameEngine::PushState(GameState* state)
{
    states.push(state);
}

void GameEngine::PopState()
{
    delete states.top();
    states.pop();
}

void GameEngine::ChangeState(GameState* state)
{
    if(!states.empty())
        PopState();
    PushState(state);
}

GameState* GameEngine::PeekState()
{
    if(states.empty()) return nullptr;
    return states.top();
}
