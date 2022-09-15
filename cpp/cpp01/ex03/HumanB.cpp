#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	weapon = NULL;
}

void	HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << name << " attacks with his ";
		std::cout << this->weapon->Weapon::getType();
		std::cout << std::endl;
	}
	else
	{
		std::cout << name << " don't have weapon ";
		std::cout << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
