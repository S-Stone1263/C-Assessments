#include "Bear.h"

Bear::Bear()
{
	m_health = 100;
	m_damage = 20;
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