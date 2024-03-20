
#pragma once
#include "Player.h"
#include "Rooms.h"
#include "String.h"
class Game
{
private:
	int map[11][11];
	Player m_player;
	Rooms m_setup;
	String m_command;
public:
	Game();
	~Game();

	void Run();

};

