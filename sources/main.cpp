#include "gameengine.hpp"
#include "playingstate.hpp"

int main()
{
    GameEngine game;

    //TODO: GameStateMenu
    game.PushState(new GameStatePlaying(&game));

    game.GameLoop();

    return 0;
}
