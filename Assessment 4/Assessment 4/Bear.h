
#pragma once
class Bear
{
private:
	int m_health;
	int m_damage;
public:
	Bear();
	void TakeDamage(int damage);
	int GetDamage();
	int GetHealth();
};

