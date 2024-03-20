#include "Sword.h"
#include <iostream>

Sword::Sword()
{
	m_damage = 30;
}

void Sword::Description()
{
	std::cout << "You look upon a beautifully crafted swords with 0 imperfections whatsoever. The gold inlaid runes running up the blade give you the idea that it is enchanted with some sort of magic..." << std::endl;
}

void Sword::Use()
{
	std::cout << "You swing the sword!" << std::endl;
}

int Sword::GetDamage()
{
	return m_damage;
}