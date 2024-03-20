
#include "Game.h"
#include "iostream"
#include "Player.h"
#include "Rooms.h"
#include "Gun.h"

void clearAndIgnore();

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
	String Gun1("Gun");
	String Fireball("Fireball");
	String LightningBolt("Lightning Bolt");
	String Teleport("Teleport");
	String Heal("Heal");
	Gun gun1;
	int inspectOrUse = 0; //Using this variable so that if a place is inspected the it doesnt continue the loop and display the area information again
	std::cout << "What would you like to do? ( move / use / inspect )" << std::endl; // add check spells and check inventory
	clearAndIgnore();
	m_command.ReadFromConsole();

	switch (m_command.ToLower().CharacterAt(0))
	{
	case 'm':
		std::cout << "Which direction would you like to move? ( north / south / east / west )" << std::endl;
		clearAndIgnore();
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
	case 'i':
		switch (map[m_player.GetX()][m_player.GetY()])
		{
		case 0:
			std::cout << "There is nothing here to inspect" << std::endl;
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
			if (encounters[3] == 0)
			{
				std::cout << "You are immediately drawn to the mystical contents of the shattered box, inside you find, three scrolls, with titles written in a long forgotten language. As you start unrolling each scroll, yellow tendrils of light begin seeping into your body, into your soul. Your vision fills with a pure yellow light, more pure than the sun itself. When looking back down at where the scrolls once were you find only ash" << std::endl;

				m_player.AddSpell(Fireball);
				m_player.AddSpell(LightningBolt);
				m_player.AddSpell(Teleport);
				m_player.PrintSpells();
				encounters[3]++;
				inspectOrUse++;
			}
			else
			{
				std::cout << "There is nothing new here to inspect" << std::endl;
				inspectOrUse++;
			}
			break;


		case 5:
			if (encounters[4] == 0)
			{
				bool solved = false;
				std::cout << "The inscription reads | Beyond this gate lies the potential to reverse the effects of damage inflicted on the user of this spell. To access this spell you must solve the following: I am a three-digit number. My second digit is four times bigger than the third digit. My first digit is three less than my second digit. Which number am I? | A random riddle in the middle of an empty forest... not suspicious at all..." << std::endl;
				while (solved == false)
				{
					int answer = 0;
					std::cout << "What would you like to do? ( solve / use an item / cast a spell )" << std::endl;
					clearAndIgnore();
					m_command.ReadFromConsole();

					switch (m_command.ToLower().CharacterAt(0))
					{
					case 's':
						clearAndIgnore();
						std::cout << "What do you think the answer is?" << std::endl;
						std::cin >> answer;
						if (answer == 141)
						{
							std::cout << "You say 141 out loud and the lock fizzles away into dust and the gate to the spell swings open as if inviting you. Following the same process as earlier with the other 3 scrolls, you feel the warm radiant light wash over you" << std::endl;
							m_player.AddSpell(Heal);
							m_player.PrintSpells();
							inspectOrUse++;
							solved = true;
						}
						else
						{
							std::cout << "You say your answer out loud but it doesnt seem to have any effect on the lock, it seems to be the wrong answer" << std::endl;
						}
						break;
					case 'u':
						clearAndIgnore();
						std::cout << "What item would you like to use" << std::endl;
						m_player.PrintInventory();
						m_command.ReadFromConsole();
						if (m_command.ToLower().CharacterAt(0) == 'g')
						{
							if (m_player.SortAndFindItem(Gun1))
							{
								gun1.Use();
								gun1.Description();
								std::cout << "The lock sits there dangling, no longer locked, you pull the lock free and the gate swings open for you ready to absorb this next spell" << std::endl;
								m_player.AddSpell(Heal);
								m_player.PrintSpells();
								inspectOrUse++;
								solved = true;
							}
							else
							{
								std::cout << "You dont have that item" << std::endl;
							}

						}
						else
						{
							std::cout << "You get the feeling looking at the cage that this will probably cause more damage to the item than the cage. Try something else" << std::endl;
						}
						break;
					case 'c':
						clearAndIgnore();
						std::cout << "What spell would you like to cast" << std::endl;
						m_player.PrintSpells();
						m_command.ReadFromConsole();
						if (m_command.ToLower().CharacterAt(0) == 't')
						{
							if (m_player.SortAndFindSpell(Teleport))
							{

							}
						}


					}

				}
				break;
			}
			else
			{
				std::cout << "Youve been here before" << std::endl;
				break;
			}



		case 6:
			std::cout << "There is a locked exit here" << std::endl;
			break;
		}
		break;

	}

	if (inspectOrUse == 0)
	{
		switch (map[m_player.GetX()][m_player.GetY()])
		{
		case 0:
			std::cout << "There is nothing but forest here" << std::endl;
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
			if (encounters[3] == 0)
				std::cout << "You find what was once a box now a shattered pile of sticks in a crater, however the contents seem... mystical..." << std::endl;
			else
			{
				std::cout << "You remember this place, this is where the magic from those 3 spells flowed into you, all that remains is the shattered box and a pile of ash" << std::endl;
			}
			break;
		case 5:
			if (encounters[4] == 0)
			{
				std::cout << "There is another scroll almost identical to the three you found earlier, except this one is within a fully fenced off area. There is a gate to access the spell but it is locked with an inscription on a hanging metal plate" << std::endl;
			}
			else
			{
				std::cout << "You recognise this fenced area as the place where you found the healing spell, however all you find in the fenced cage is a pile of ash" << std::endl;
			}
			break;
		case 6:
			std::cout << "There is a locked exit here" << std::endl;
			break;

		}
	}

	m_player.GetPosition();
}
