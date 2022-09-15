#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : Name(name)
{
	std::cout << "DiamondTrap constructor start" << std::endl;
	ClapTrap::Name = Name + "_clap_name";
	this->HitPoints = FragTrap::HP_VAL;
	this->Energy = ScavTrap::EP_VAL;
	this->Damage = FragTrap::AD_VAL;
}

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor start" << std::endl;
	this->Name = "";
	ClapTrap::Name = Name + "_clap_name";
	this->HitPoints = FragTrap::HP_VAL;
	this->Energy = ScavTrap::EP_VAL;
	this->Damage = FragTrap::AD_VAL;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap copy constructor start" << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& c)
{
	if (&c != this)
	{
		this->Name = c.Name;
		ClapTrap::Name = Name + "_clap_name";
		this->HitPoints = c.HitPoints;
		this->Energy = c.Energy;
		this->Damage = c.Damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor start" << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is ";
	std::cout << Name;
	std::cout << ". My clapTrap name is ";
	std::cout << ClapTrap::Name;
	std::cout << std::endl;
}
