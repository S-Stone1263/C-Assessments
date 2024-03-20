
#include "Player.h"
#include "iostream"
#include "String.h"

Player::Player()
{
	String defaultSpell("No Spells");
	String defaultInventory("No items");
	m_posX = 6;
	m_posY = 6;
	numSpells = 0;
	m_spells = new String[1];
	m_spells[0] = defaultSpell;
	m_inventory = new String[1];
	m_inventory[0] = defaultInventory;
	numInventory = 0;
}

Player::~Player()
{
	delete[] m_spells;
	delete[] m_inventory;
}

void Player::North()
{
	if (m_posX >= 1)
	{
		m_posX--;
	}
	else
	{
		std::cout << "You have reached the boundary" << std::endl;
	}
}

void Player::South()
{
	if (m_posX <= 9)
	{
		m_posX++;
	}
	else
	{
		std::cout << "You have reached the boundary" << std::endl;
	}
}

void Player::East()
{
	if (m_posY <= 9)
	{
		m_posY++;
	}
	else
	{
		std::cout << "You have reached the boundary" << std::endl;
	}
}

void Player::West()
{
	if (m_posY >= 1)
	{
		m_posY--;
	}
	else
	{
		std::cout << "You have reached the boundary" << std::endl;
	}
}


void Player::GetPosition()
{
	std::cout << "(" << m_posX << ", " << m_posY << ")" << std::endl;
}

int Player::GetX()
{
	return m_posX;
}

int Player::GetY()
{
	return m_posY;
}

void Player::AddSpell(String& newSpell)
{
	if (numSpells == 0)
	{
		numSpells++;
		delete[] m_spells;
		m_spells = new String[numSpells];
		m_spells[0] = newSpell;
	}
	else
	{
		String* temp = new String[numSpells];
		for (int i = 0; i < numSpells; i++)
		{
			temp[i] = m_spells[i];
		}
		delete[] m_spells;
		numSpells++;
		m_spells = new String[numSpells];

		for (int i = 0; i < numSpells - 1; i++)
		{
			m_spells[i] = temp[i];
		}

		delete[] temp;
		m_spells[numSpells - 1] = newSpell;
	}



}

void Player::PrintSpells()
{
	std::cout << "You know the following spells:" << std::endl;
	for (int i = 0; i < numSpells; i++)
	{
		std::cout << m_spells[i].Cstr() << std::endl;
	}
}

int Player::GetNumSpells() //dev function while testing
{
	return numSpells;
}

String* Player::GetSpells() //dev function while testing
{
	return m_spells;
}

void Player::AssignSpells(String* temp) //dev function while testing
{
	m_spells = temp;
}

bool Player::SortAndFindSpell(String& spell)
{
	if (numSpells == 0)
	{
		return false;
	}

	String* temp = new String[numSpells];
	int currentTempSpell = 0;
	for (char j = 65; j < 91; j++)
	{
		for (int i = 0; i < numSpells; i++)
		{
			if (m_spells[i].CharacterAt(0) == j)
			{
				temp[currentTempSpell] = m_spells[i];
				temp[currentTempSpell].Cstr();
				currentTempSpell++;
			}

		}
	}

	m_spells = temp;


	char key = spell.CharacterAt(0);
	int start = 0;
	int end = numSpells - 1;

	bool match = false;

	while (match == false)
	{
		int middle = (start + end) / 2;
		bool lessThan = key < m_spells[middle].CharacterAt(0);
		if (m_spells[middle].CharacterAt(0) == key)
		{
			std::cout << "true" << std::endl;
			match = true;
			return true;
		}
		else if (start == middle && m_spells[end].CharacterAt(0) != key || end == middle && m_spells[start].CharacterAt(0) != key)
		{
			std::cout << "false" << std::endl;
			return false;
			break;
		}
		else if (lessThan == true)
		{
			end = middle - 1;
		}
		else if (lessThan == false)
		{
			start = middle + 1;
		}


	}


}


void Player::AddItem(String& newItem)
{
	if (numInventory == 0)
	{
		numInventory++;
		delete[] m_inventory;
		m_inventory = new String[numInventory];
		m_inventory[0] = newItem;
	}
	else
	{
		String* temp = new String[numInventory];
		for (int i = 0; i < numInventory; i++)
		{
			temp[i] = m_inventory[i];
		}
		delete[] m_inventory;
		numInventory++;
		m_inventory = new String[numInventory];

		for (int i = 0; i < numInventory - 1; i++)
		{
			m_inventory[i] = temp[i];
		}

		delete[] temp;
		m_inventory[numInventory - 1] = newItem;
	}



}

void Player::PrintInventory()
{
	std::cout << "You have the following items:" << std::endl;
	for (int i = 0; i < numInventory; i++)
	{
		std::cout << m_inventory[i].Cstr() << std::endl;
	}
}

bool Player::SortAndFindItem(String& item)
{
	if (numInventory == 0)
	{
		return false;
	}

	String* temp = new String[numInventory];
	int currentTempItem = 0;
	for (char j = 65; j < 91; j++)
	{
		for (int i = 0; i < numInventory; i++)
		{
			if (m_inventory[i].CharacterAt(0) == j)
			{
				temp[currentTempItem] = m_inventory[i];
				temp[currentTempItem].Cstr();
				currentTempItem++;
			}

		}
	}

	m_inventory = temp;


	char key = item.CharacterAt(0);
	int start = 0;
	int end = numInventory - 1;

	bool match = false;

	while (match == false)
	{
		int middle = (start + end) / 2;
		bool lessThan = key < m_inventory[middle].CharacterAt(0);
		if (m_inventory[middle].CharacterAt(0) == key)
		{
			match = true;
			return true;
		}
		else if (start == middle && m_inventory[end].CharacterAt(0) != key || end == middle && m_inventory[start].CharacterAt(0) != key)
		{
			return false;
			break;
		}
		else if (lessThan == true)
		{
			end = middle - 1;
		}
		else if (lessThan == false)
		{
			start = middle + 1;
		}


	}


}

void Player::TakeDamage(int damage)
{
	m_health = m_health - damage;
}

void Player::Heal(int health)
{
	m_health = m_health + health;
}

int Player::GetHealth()
{
	return m_health;
}
