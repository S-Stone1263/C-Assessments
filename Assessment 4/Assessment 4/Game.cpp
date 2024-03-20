#include "Game.h"
#include "iostream"
#include "Player.h"
#include "Rooms.h"
#include "Gun.h"

Game::Game()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			map[i][j] = 0;
		}
	}

	map[m_setup.GetSwordLocation()[0]][m_setup.GetSwordLocation()[1]] = 1;
	map[m_setup.GetBearLocation()[0]][m_setup.GetBearLocation()[1]] = 2;
	map[m_setup.GetWreckageLocation()[0]][m_setup.GetWreckageLocation()[1]] = 3;
	map[m_setup.GetThreeSpellsLocation()[0]][m_setup.GetThreeSpellsLocation()[1]] = 4;
	map[m_setup.GetNewSpellLocation()[0]][m_setup.GetNewSpellLocation()[1]] = 5;
	map[m_setup.GetGateLocation()[0]][m_setup.GetGateLocation()[1]] = 6;
}

Game::~Game()
{
}

void Game::Run()
{
	while (m_player.GetNumSpells() == 0)
	{
		String Fireball("Fireball");
		m_player.AddSpell(Fireball);
		String LightningBolt("Lightning Bolt");
		m_player.AddSpell(LightningBolt);
		String Heal("Heal");
		m_player.AddSpell(Heal);
		String Teleport("Teleport");
		m_player.AddSpell(Teleport);
		String AppleThrow("Apple Throw");
		m_player.AddSpell(AppleThrow);
		String Zebra("Zebra");
		m_player.AddSpell(Zebra);
		m_player.SortAndFindSpell(Zebra);
		m_player.PrintSpells();
	}



	std::cout << "What would you like to do? ( move / use / inspect )" << std::endl;
	m_command.ReadFromConsole();

	switch (m_command.ToLower().CharacterAt(0))
	{
	case 'm':
		std::cout << "Which direction would you like to move? ( north / south / east / west )" << std::endl;
		m_command.ReadFromConsole();
		if (m_command.ToLower().CharacterAt(0) == 'n')
		{
			m_player.North();
		}
		else if (m_command.ToLower().CharacterAt(0) == 's')
		{
			m_player.South();
		}
		else if (m_command.ToLower().CharacterAt(0) == 'e')
		{
			m_player.East();
		}
		else if (m_command.ToLower().CharacterAt(0) == 'w')
		{
			m_player.West();
		}
		break;
	}


	switch (map[m_player.GetX()][m_player.GetY()])
	{
	case 0:
		std::cout << "There is nothing here" << std::endl;
		break;
	case 1:
		std::cout << "There is a sword here" << std::endl;
		break;
	case 2:
		std::cout << "There is a bear here" << std::endl;
		break;
	case 3:
		std::cout << "There is wreckage here" << std::endl;
		break;
	case 4:
		std::cout << "There are 3 spells here" << std::endl;
		break;
	case 5:
		std::cout << "There is a new spell here" << std::endl;
		break;
	case 6:
		std::cout << "There is a locked exit here" << std::endl;
		break;

	}

	m_player.GetPosition();

}