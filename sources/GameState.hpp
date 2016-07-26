#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include "Game.hpp"

class GameEngine;

class GameState
{
public:
    virtual void input(GameEngine* game) = 0;
    virtual void update(GameEngine* game) = 0;
    virtual void draw(GameEngine* game) = 0;

    void changeState(GameEngine* game, GameState* state);

    GameState();
    ~GameState();
};

#endif // _GAMESTATE_HPP_
