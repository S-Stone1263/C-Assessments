
#include "Gun.h"
#include "iostream"

Gun::Gun()
{
	m_ammo = 1;
}

void Gun::Description()
{
	if (m_ammo == 1)
		std::cout << "You find a GUN in the wreckage, it seems to have lost its mag in the crash. Pulling back the slide of the pistol, you find there is one in the chamber... best to use it wisely" << std::endl;
	else
	{
		std::cout << "Looking down at the freshly fired gun, the last shot seems to have caused a malfunction as the slide is no longer attached to the gun, rendering it useless even if more bullets were found, you drop the pieces that were once a pistol";
	}
}

void Gun::Use()
{
	std::cout << "You fire the gun" << std::endl;
	m_ammo--;
}
