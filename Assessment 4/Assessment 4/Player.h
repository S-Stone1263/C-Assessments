
#pragma once
#include "String.h"
class Player
{
private:
	int m_health;
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
	bool SortAndFindSpell(String& spell);
	void AddItem(String& newItem);
	void PrintInventory();
	bool SortAndFindItem(String& item);
	void TakeDamage(int damage);
	void Heal(int health);
	int GetHealth();

};

