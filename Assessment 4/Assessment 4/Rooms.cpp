#include "Rooms.h"
#include <chrono>
#include <iostream>
#include <ctime>

Rooms::Rooms()
{
	auto time = std::chrono::system_clock::now();
	int seed = std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
	srand(seed);

	int gateLoc = rand() % 4 + 1;

	switch (gateLoc)
	{
	case 1:
		gate[0] = 6;
		gate[1] = 0;
		break;

	case 2:
		gate[0] = 6;
		gate[1] = 10;
		break;

	case 3:
		gate[0] = 0;
		gate[1] = 6;
		break;

	case 4:
		gate[0] = 10;
		gate[1] = 6;
		break;
	}


	sword[0] = rand() % 4;
	bear[0] = rand() % 4 + 7;
	wreckage[0] = rand() % 4;
	threeSpells[0] = rand() % 3 + 4;
	newSpell[0] = rand() % 4 + 7;

	sword[1] = rand() % 4;
	bear[1] = rand() % 4;
	wreckage[1] = rand() % 4 + 7;
	threeSpells[1] = rand() % 3 + 4;
	newSpell[1] = rand() % 4 + 7;

	std::cout << "Sword is at (" << sword[0] << ", " << sword[1] << ")" << std::endl;
	std::cout << "Bear is at (" << bear[0] << ", " << bear[1] << ")" << std::endl;
	std::cout << "Wreckage is at (" << wreckage[0] << ", " << wreckage[1] << ")" << std::endl;
	std::cout << "threeSpells is at (" << threeSpells[0] << ", " << threeSpells[1] << ")" << std::endl;
	std::cout << "newSpell is at (" << newSpell[0] << ", " << newSpell[1] << ")" << std::endl;
	std::cout << "gate is at (" << gate[0] << ", " << gate[1] << ")" << std::endl;

}


int* Rooms::GetSwordLocation()
{
	return sword;
}

int* Rooms::GetBearLocation()
{
	return bear;
}

int* Rooms::GetWreckageLocation()
{
	return wreckage;
}

int* Rooms::GetThreeSpellsLocation()
{
	return threeSpells;
}

int* Rooms::GetNewSpellLocation()
{
	return newSpell;
}

int* Rooms::GetGateLocation()
{
	return gate;
}
