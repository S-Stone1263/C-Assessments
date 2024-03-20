
#pragma once
#include "Item.h"
class Gun : public Item
{
private:
	int m_ammo;
	int m_damage;
public:
	Gun();
	void Description() override;
	void Use() override;
	int GetAmmo();
	int GetDamage();
};

