#include "Bear.h"

Bear::Bear()
{
}

void Bear::TakeDamage(int damage)
{
	m_health = m_health - damage;
}

int Bear::GetDamage()
{
	return m_damage;
}

int Bear::GetHealth()
{
	return m_health;
}