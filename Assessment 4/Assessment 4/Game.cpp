#include "Game.h"
#include "iostream"
#include "Player.h"
#include "Rooms.h"
#include "Gun.h"
#include "Sword.h"
#include "Knife.h"
#include "String.h"
#include "Bear.h"
#include <windows.h>

void clearAndIgnore();

Game::Game()
{
	running = true;

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

bool Game::RunningStatus()
{
	return running;
}

void Game::Run()
{
	String Gun1("Gun");
	String Fireball("Fireball");
	String LightningBolt("Lightning Bolt");
	String Teleport("Teleport");
	String Heal("Heal");
	String Sword1("Sword");
	String Knife1("Knife");
	String Key("Key");
	Knife knife1;
	Sword sword1;
	Gun gun1;
	Bear bear;
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
			if (encounters[0] == 0)
			{
				bool solved = false;
				std::cout << "The inscription reads | Here lies the sword of the last worthy king, cursed to stay in this stone until a person deemed worthy draws it from its resting place" << std::endl;
				while (solved == false)
				{
					int answer = 0;
					std::cout << "What would you like to do? ( pull the sword / use an item / cast a spell )" << std::endl;
					clearAndIgnore();
					m_command.ReadFromConsole();

					switch (m_command.ToLower().CharacterAt(0))
					{
					case 'p':
						std::cout << "You reach through the thorny vines your arm and torso getting shredded by the massive rose like thorns until your hand finds the handle of the sword. Getting a firm grip and pulling the sword slides like butter through the stone you manage to pull the sword free" << std::endl;
						m_player.TakeDamage(10);
						m_player.AddItem(Sword1);
						sword1.Description();
						inspectOrUse++;
						solved = true;
						std::cout << "You take 10 points of damage, you have " << m_player.GetHealth() << " hitpoints remaining" << std::endl;
						break;
					case 'u':
						clearAndIgnore();
						std::cout << "What item would you like to use" << std::endl;
						m_player.PrintInventory();
						m_command.ReadFromConsole();
						if (m_command.ToLower().CharacterAt(0) == 'k')
						{
							if (m_player.SortAndFindItem(Knife1))
							{
								if (knife1.GetDurability() > 0)
								{
									knife1.Use();
									std::cout << "Cutting the vines away, you expose the sword and are able to cleanly wrap your hand around the handle and pull the sword out of the stone like its sliding through butter" << std::endl;
									m_player.AddItem(Sword1);
									sword1.Description();
									inspectOrUse++;
									solved = true;
								}
								else
								{
									knife1.Description();
								}

							}
							else
							{
								std::cout << "You dont have that item" << std::endl;
							}

						}
						else
						{
							std::cout << "You get the feeling looking at the mass of vines that this will probably not be very effective. Try something else" << std::endl;
						}
						break;
					case 'c':
						clearAndIgnore();
						std::cout << "What spell would you like to cast" << std::endl;
						m_player.PrintSpells();
						m_command.ReadFromConsole();
						if (m_command.ToLower().CharacterAt(0) == 'f')
						{
							if (m_player.SortAndFindSpell(Fireball))
							{
								std::cout << "You focus on the fireball spell that you learnt from the scroll, imagining the hottest flames you can remember seeing. Opening your eyes and looking down at your hand you see a blue sphere of pure fire ready to be thrown. Throwing this at the vines causes them to violently erupt in flames" << std::endl;
								std::cout << "Letting the flames die out, the vines have been completely burnt away, allowing you to be able to freely grab the handle of the sword, as you do it slides out of the solid stone like it was butter" << std::endl;
								m_player.AddItem(Sword1);
								sword1.Description();
								inspectOrUse++;
								solved = true;
							}
							else
							{
								std::cout << "You dont know how to cast that spell" << std::endl;
							}
						}
						else
						{
							std::cout << "You get the feeling that casting that will have little effect on the mass of vines" << std::endl;
						}


					}

				}
				break;
				encounters[4] = 1;
			}
			else
			{
				std::cout << "There is nothing new to inspect here" << std::endl;
				break;
			}
		case 2:
			if (encounters[1] == 0)
			{
				std::cout << "You walk through the forest and start to notice the trees are thinning out and you can see a clearing ahead. Walking through you notice 2 things. Less noticeable, a shiny extravagant key sitting on the ground. But more importantly you see a massive brown bear already running in your direction!" << std::endl;
				while (bear.GetHealth() > 0 && m_player.GetHealth() > 0)
				{
					std::cout << "What would you like to do? ( use item / cast spell )" << std::endl;
					clearAndIgnore();
					m_command.ReadFromConsole();
					switch (m_command.ToLower().CharacterAt(0))
					{
					case 'u':
						std::cout << "What item would you like to use?" << std::endl;
						clearAndIgnore();
						m_command.ReadFromConsole();
						switch (m_command.ToLower().CharacterAt(0))
						{
						case 'g':
							if (m_player.SortAndFindItem(Gun1))
							{
								if (gun1.GetAmmo() == 1)
								{
									gun1.Use();
									gun1.Description();
									bear.TakeDamage(gun1.GetDamage());
								}
								else
								{
									gun1.Use();
								}
							}
							else
							{
								std::cout << "You dont have that item" << std::endl;
							}
							break;

						case 'k':
							if (m_player.SortAndFindItem(Knife1))
							{
								if (knife1.GetDurability() < 0)
								{
									knife1.Use();
									bear.TakeDamage(knife1.GetDamage());
								}
								else
								{
									knife1.Use();
								}
							}
							else
							{
								std::cout << "You dont have that item" << std::endl;
							}
							break;
						case 's':
							if (m_player.SortAndFindItem(Sword1))
							{
								sword1.Use();
								bear.TakeDamage(sword1.GetDamage());
							}
							else
							{
								std::cout << "You dont have that item" << std::endl;
							}
							break;
						}
						break;
					case 'c':
						std::cout << "What spell would you like to cast?" << std::endl;
						clearAndIgnore();
						m_command.ReadFromConsole();
						switch (m_command.ToLower().CharacterAt(0))
						{
						case 'f':
							std::cout << "You focus upon your palm, building up the energy coursing through your veins and condensing into a sphere. You throw the fireball at the bear and it explodes upon impact! However, it wasn't as effective as you thought it would be" << std::endl;
							bear.TakeDamage(15);
							break;
						case 'l':
							std::cout << "You begin to focus on spellcasting, not sure what to cast next. While making this decision a storm cloud begins forming above the bear. Condensing the energy in that stormcloud, you bring it all down on the bears head in a bright flash of lightning! Followed by a thunderous BOOM not a second later! The bear convulses upon the hit and takes a few seconds to recover" << std::endl;
							bear.TakeDamage(35);
							break;
						case 't':
							std::cout << "You begin to panic upon seeing this bear charging at you and all you can think about is how you want as much space as possible between this bear and you. In the instant that thought flows through your brain, you see the bear vanish from your sightline..." << std::endl;
							Sleep(5);
							std::cout << "You begin to hear a faint roaring sound, and the panic starts to set back in wondering where the bear is coming from, before you realise... its coming from... above???" << std::endl;
							std::cout << "SPLAT" << std::endl;
							std::cout << "About 20 metres away from where the bear dissapeared, you see the corpse or whats left of the bear, it is dead... very dead" << std::endl;
							bear.TakeDamage(100);
							break;
						case 'h':
							std::cout << "Focusing on the wounds you have sustained throughout this experience, some of them begin to close and heal, small wounds completely vanishing and the larger wounds look like theyve been healing for several weeks already" << std::endl;
							if (m_player.GetHealth() > (100 - 15))
							{
								int healing;
								healing = 100 - m_player.GetHealth();
								m_player.Heal(healing);
							}
							else
							{
								m_player.Heal(15);
							}


						}
					}
				}
			}

			break;
		case 3:
			if (encounters[2] == 0)
			{
				std::cout << "In the smoldering wreckage of what once was a plane, you manage to find two things" << std::endl;
				gun1.Description();
				knife1.Description();
				m_player.AddItem(Gun1);
				m_player.AddItem(Knife1);
				m_player.PrintInventory();
				encounters[2]++;
				break;
			}
			else
			{
				std::cout << "There is nothing new to inspect at the wreckage" << std::endl;
			}


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
							encounters[4]++;
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
								if (gun1.GetAmmo() == 1)
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
									gun1.Description();
								}

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
								std::cout << "You focus on the teleport spell, trying your hardest to will yourself towards the scroll, wishing that the lock would dissapear and as you finish that thought the lock blinks out of existence and the door falls open" << std::endl;
								m_player.AddSpell(Heal);
								m_player.PrintSpells();
								inspectOrUse++;
								solved = true;
							}
							else
							{
								std::cout << "You dont know how to cast that spell" << std::endl;
							}
						}
						else
						{
							std::cout << "You get the feeling that casting that offensive type spell may damage the scroll" << std::endl;
						}


					}

				}
				break;
				encounters[4] = 1;
			}
			else
			{
				std::cout << "There is nothing new to inspect here" << std::endl;
				break;
			}



		case 6:
			if (m_player.SortAndFindItem(Key))
			{
				std::cout << "There is a locked exit here and you seem to remember finding a key after your battle with the bear. Inserting the key it seems to automatically drift from your hand and into the lock and turns opening the exit. As you take one step through the dark you immediately feel a sharp pain in the side of your neck before your vision fades..." << std::endl;
				running = false;
			}
			else
			{
				std::cout << "The door seems to be magically locked, the lock being somewhat in this realm and also not, when you go to touch it your hand passes through, but with all the magic coursing through your veins, you get the sense that a specific key will certainly unlock this" << std::endl;
			}
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
			if (encounters[2] == 0)
			{
				std::cout << "As you apporoach you see the smoking wreckage of a plane, mostly burnt out, you assume this is how you ended up in this forest..." << std::endl;
			}
			else
			{
				std::cout << "You've come across this spot already, this is the wreckage of the plane where you found the knife and the gun" << std::endl;
			}
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