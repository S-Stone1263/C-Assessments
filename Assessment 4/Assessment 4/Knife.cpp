
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
		std::cout << "You swing the knife hoping it doesn't break!" << std::endl;
		m_durability--;
	}
	else if (m_durability == 0)
	{
		std::cout << "You go to swing the knife but as you swing you find that the blade snaps just from the air resistance and you finish your swign with just the handle" << std::endl;
		m_durability--;
	}
	else
	{
		std::cout << "The knife is broken, you only have the handle" << std::endl;
	}
}

int Knife::GetDurability()
{
	return m_durability;
}

int Knife::GetDamage()
{
	return 0;
}
