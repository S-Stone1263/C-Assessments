#pragma once
#include "Item.h"
class Sword : public Item
{
private:
	int m_damage;
public:
	Sword();
	void Description() override;
	void Use() override;
	int GetDamage();
};
