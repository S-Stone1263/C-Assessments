
#pragma once
#include "String.h"
class Player
{
private:
	int m_posX;
	int m_posY;
	String* m_spells;
	int numSpells;
	String* m_inventory;
	int numInventory;
public:
	Player();
	~Player();
	void North();
	void South();
	void East();
	void West();
	void GetPosition();
	int GetX();
	int GetY();
	void AddSpell(String& newSpell);
	void PrintSpells();
	int GetNumSpells();
	String* GetSpells();
	void AssignSpells(String*);
	bool SortAndFindSpell(String& spell);
	void AddItem(String& newItem);
	void PrintInventory();
	bool SortAndFindItem(String& item);

};

