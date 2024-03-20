
#pragma once
class Rooms
{
private:
	int sword[2];
	int bear[2];
	int gate[2];
	int wreckage[2];
	int threeSpells[2];
	int newSpell[2];

public:
	Rooms();

	int* GetSwordLocation();
	int* GetBearLocation();
	int* GetWreckageLocation();
	int* GetThreeSpellsLocation();
	int* GetNewSpellLocation();
	int* GetGateLocation();
};

