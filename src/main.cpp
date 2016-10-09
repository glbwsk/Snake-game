#include "gameengine.hpp"
#include "menustate.hpp"

int main()
{
    GameEngine game;

    game.ChangeState(new GameStateMenu(&game));

    game.GameLoop();

    return 0;
}
