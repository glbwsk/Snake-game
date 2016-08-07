#include "gameengine.hpp"
#include "playingstate.hpp"
#include "menustate.hpp"

int main()
{
    GameEngine game;

    //!TODO: GameStateMenu
    //game.ChangeState(new GameStateMenu( &game ));
    game.ChangeState(new GameStatePlaying(&game));

    return 0;
}
