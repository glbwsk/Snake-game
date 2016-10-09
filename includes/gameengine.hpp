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

    //setters & getters
    void Quit() { gameRunning = false; }
    int GetWinHeight() { return winHeight; }
    int GetWinWidth() { return winWidth; }
    int GetFrameLimit() { return maxFrames; }
    sf::RenderWindow* GetWindow() { return &window; }

private:

    //the stack of game states
    std::stack<GameState*> states;

    sf::RenderWindow window;

    bool gameRunning;
    int winWidth, winHeight;
    int maxFrames;
};
