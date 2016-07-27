#include <stack>

#include <SFML/Graphics.hpp>

#include "gameengine.hpp"
#include "gamestate.hpp"

GameEngine::GameEngine()
{
    window.create(sf::VideoMode(960, 540), "SNAKE");
    window.setFramerateLimit(60);
    gameRunning=true;
    srand(time(NULL));
}

GameEngine::~GameEngine()
{
    while(!states.empty()) PopState();
}

void GameEngine::GameLoop()
{
    srand(time(NULL));

    sf::Clock clock;
    sf::Time elapsed;
    float time;

    while(gameRunning)
    {
        elapsed = clock.restart();
        time = elapsed.asSeconds();

        if(PeekState() == nullptr) continue;
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
