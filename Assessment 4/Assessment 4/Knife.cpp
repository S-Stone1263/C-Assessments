#include "Knife.h"
#include <iostream>

Knife::Knife()
{
	m_damage = 15;
	m_durability = 5;
}

void Knife::Description()
{
	std::cout << "You find a rusty damaged knife, it will do the job but probably dont trust it" << std::endl;
}

void Knife::Use()
{
	if (m_durability > 0)
	{
		std::cout << "You swing the knife hoping it doesn't break!"

	}
}

int Knife::GetDamage()
{
	return 0;
}