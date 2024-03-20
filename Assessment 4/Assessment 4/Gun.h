#pragma once
#include "Item.h"
class Gun : public Item
{
private:
	int m_ammo;
public:
	Gun();
	void Description() override;
	void Use() override;
};
