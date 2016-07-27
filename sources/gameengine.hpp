#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class GameEngine
{
public:

    GameEngine();
    ~GameEngine();

    void GameLoop();
    void PushState(GameState* state);
    void PopState();
    void ChangeState(GameState* state);
    GameState* PeekState();

    void Quit() { gameRunning = false; }

private:

    sf::RenderWindow window;
    std::stack<GameState*> states;
    bool gameRunning;
};
