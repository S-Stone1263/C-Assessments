
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
	m_health = 100;
}

Player::~Player()
{
	delete[] m_spells;
	delete[] m_inventory;
}
//following functions update the player position by one unit in the selected direction
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

//prints the position of the user
void Player::GetPosition()
{
	std::cout << "(" << m_posX << ", " << m_posY << ")" << std::endl;
}
//returns x value of coordinate
int Player::GetX()
{
	return m_posX;
}

//return y value of coordinate
int Player::GetY()
{
	return m_posY;
}

//adds a spell to the players known spells
void Player::AddSpell(String& newSpell)
{
	if (numSpells == 0)
	{
		//if the player knows no spells the first spell added uses this logic
		//adds 1 to the number of known spells and deletes the current container of spells as it is empty
		numSpells++;
		delete[] m_spells;
		//creating a new container of appropriate size
		m_spells = new String[numSpells];
		//adds the spell into the container
		m_spells[0] = newSpell;
	}
	else
	{
		//creates a new array of appropriate size of known spells
		String* temp = new String[numSpells];

		//copies the contents of the spell container to the temporary array
		for (int i = 0; i < numSpells; i++)
		{
			temp[i] = m_spells[i];
		}
		//deletes current spell container
		delete[] m_spells;

		//adds new spell to known number of spells
		numSpells++;

		//create new container
		m_spells = new String[numSpells];

		//copy components of temp into new spell container
		for (int i = 0; i < numSpells - 1; i++)
		{
			m_spells[i] = temp[i];
		}

		//delete temporary array and add the new spell into the empty spot in the container
		delete[] temp;
		m_spells[numSpells - 1] = newSpell;
	}



}

//prints the known spells
void Player::PrintSpells()
{
	std::cout << "You know the following spells:" << std::endl;
	for (int i = 0; i < numSpells; i++)
	{
		std::cout << m_spells[i].Cstr() << std::endl;
	}
}

//sorts the spells and finds a specific spell using binary search
bool Player::SortAndFindSpell(String& spell)
{
	//if the user knows no spells the find function returns false
	if (numSpells == 0)
	{
		return false;
	}

	//creating a temp array to store the alphabetically sorted spells
	String* temp = new String[numSpells];
	int currentTempSpell = 0;
	//loops through the letters of the alphabet and checks the first character of spell against it, if it finds a match, the spell is stored in the new string
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
	//replaces the pointer of m_spells with the pointer of temp (which points to the location of the sorted array)
	m_spells = temp;

	//key is the first letter of the desired spell
	char key = spell.CharacterAt(0);
	int start = 0;
	int end = numSpells - 1;

	bool match = false;
	//enters a while loop until the match is found
	while (match == false)
	{
		int middle = (start + end) / 2;
		bool lessThan = key < m_spells[middle].CharacterAt(0);

		//if match found do this
		if (m_spells[middle].CharacterAt(0) == key)
		{
			std::cout << "true" << std::endl;
			match = true;
			return true;
		}

		//if no match is found and there are 2 spells left enter this
		else if (start == middle && m_spells[end].CharacterAt(0) != key || end == middle && m_spells[start].CharacterAt(0) != key)
		{
			std::cout << "false" << std::endl;
			return false;
			break;
		}
		//if the key is less than the current middle, set the end to the next unchecked spell before the current middle
		else if (lessThan == true)
		{
			end = middle - 1;
		}
		//if the key is less than the current middle, set the start to the next unchecked spell after the current middle
		else if (lessThan == false)
		{
			start = middle + 1;
		}


	}


}


//same as the spell versions of add, sort and find, print but for items
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

//health logic
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
