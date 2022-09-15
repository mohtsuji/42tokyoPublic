#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor start" << std::endl;
	this->Name = name;
	this->HitPoints = 100;
	this->Energy = 100;
	this->Damage = 30;
}

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor start" << std::endl;
	this->Name = "";
	this->HitPoints = 100;
	this->Energy = 100;
	this->Damage = 30;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap copy constructor start" << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator=(const FragTrap& c)
{
	if (&c != this)
	{
		this->Name = c.Name;
		this->HitPoints = c.HitPoints;
		this->Energy = c.Energy;
		this->Damage = c.Damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap deconstructor start" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap Please positive high fives! by ";
	std::cout << this->Name << std::endl;
}
