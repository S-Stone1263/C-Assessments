
#pragma once
#include "Item.h"
class Knife : public Item
{
private:
	int m_damage;
	int m_durability;
public:
	Knife();
	void Description() override;
	void Use() override;
	int GetDamage();
};

