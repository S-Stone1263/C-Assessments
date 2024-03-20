
#include "Game.h"

//list of things that need to be added/improved: 
//input security and default statements for incorrect inputs
//better combat mechanics
//multiple enemies and use an inheritance system instead of just the one class
//a "sound" based system to give the user an idea of which direction each encounter is in
//implement exits from each encounter before completion



//some "dev" features have been left in so the game is actually playable, the coordinate system is the main thing. Use this to get to each encounter
//*IMPORTANT NOTE* get some spells or items before bear encounter as you will die or get stuck in an infinite loop without them due to not having an exit from that encounter
int main()
{
	Game game;
	while (game.RunningStatus())
	{
		game.Run();
	}
	return 0;
}
