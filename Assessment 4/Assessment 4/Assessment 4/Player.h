#pragma once
class Player
{
private:
	int m_health;
	int m_posX;
	int m_posY;
	char* m_spells;
public:
	Player();
	~Player();

	bool FindSpell();
};

