
#include "Game.h"
#include "Rooms.h"
#include "Player.h"


int main()
{
	Game game;
	while (game.RunningStatus())
	{
		game.Run();
	}
	return 0;
}
