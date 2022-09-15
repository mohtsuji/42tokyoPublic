#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor start" << std::endl;
	this->Name = name;
	this->HitPoints = 100;
	this->Energy = 50;
	this->Damage = 20;
}

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor start" << std::endl;
	this->Name = "";
	this->HitPoints = 100;
	this->Energy = 50;
	this->Damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &c)
{
	std::cout << "ScavTrap copy constructor start" << std::endl;
	*this = c;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& c)
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap deconstructor start" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	this->Energy -= 5;
	std::cout << "ScavTrap ";
	std::cout << this->Name;
	std::cout << " attack ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << this->Damage;
	std::cout << " points of damage!";
	std::cout << " I spent 5 Energy. The rest my Energy is ";
	std::cout << this->Energy;
	std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap ";
	std::cout << this->Name;
	std::cout << " enterred in Gate keeper mode. ";
	std::cout << std::endl;
}
