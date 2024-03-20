
#include "Gun.h"
#include "iostream"

Gun::Gun()
{
	m_ammo = 1;
	m_damage = 100;
}

void Gun::Description()
{
	if (m_ammo == 1)
		std::cout << "You find a GUN in the wreckage, it seems to have lost its mag in the crash. Pulling back the slide of the pistol, you find there is one in the chamber... best to use it wisely" << std::endl;
	else
	{
		std::cout << "Looking down at the freshly fired gun, the last shot seems to have caused a malfunction as the slide is no longer attached to the gun, rendering it useless even if more bullets were found, you drop the pieces that were once a pistol" << std::endl;
	}
}

void Gun::Use()
{
	if (m_ammo == 1)
	{
		std::cout << "You fire the gun, its blast ringing out through the forest, and deafening you for a few seconds" << std::endl;
		m_ammo--;
	}
	else
	{
		std::cout << "You remember back to the moment when you fired the gun previously and it fell apart in your hands, using the gun is no longer an option, maybe you shouldn't have used the bullet..." << std::endl;
	}

}

int Gun::GetDamage()
{
	return m_damage;
}
