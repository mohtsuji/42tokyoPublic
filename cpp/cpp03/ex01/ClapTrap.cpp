#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: Name(name), HitPoints(10), Energy(10), Damage(100)
{
	std::cout << "ClapTrap constructor start" << std::endl;
}

ClapTrap::ClapTrap(void)
	: Name(""), HitPoints(10), Energy(10), Damage(100)
{
	std::cout << "ClapTrap default constructor start" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c)
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

ClapTrap::ClapTrap(const ClapTrap& c)
{
	*this = c;
	std::cout << "ClapTrap copy constructor start" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap deconstructor start" << std::endl;
}

unsigned int ClapTrap::GetHitPoints() const
{
	return (this->HitPoints);
}

unsigned int ClapTrap::GetEnergy() const
{
	return (this->Energy);
}

unsigned int ClapTrap::GetDamage() const
{
	return (this->Damage);
}

void ClapTrap::SetHitPoints(unsigned int hitpoints)
{
	HitPoints = hitpoints;
}

void ClapTrap::SetEnergy(unsigned int energy)
{
	Energy = energy;
}

void ClapTrap::SetDamage(unsigned int damage)
{
	Damage = damage;
}

void	ClapTrap::attack(std::string const & target)
{
	this->Energy -= 5;
	std::cout << "ClapTrap ";
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->GetHitPoints() < amount)
		this->SetHitPoints(0);
	else
		this->SetHitPoints(this->GetHitPoints() - amount);
	std::cout << "ClapTrap ";
	std::cout << this->Name;
	std::cout << " recieved ";
	std::cout << amount;
	std::cout << ". The rest my HP is ";
	std::cout << this->GetHitPoints();
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->GetHitPoints() + amount >= 200)
		this->SetHitPoints(200);
	else
		this->SetHitPoints(this->GetHitPoints() + amount);
	std::cout << "ClapTrap ";
	std::cout << this->Name;
	std::cout << " recieved power ";
	std::cout << amount;
	std::cout << ". The rest my HP is ";
	std::cout << this->GetHitPoints();
	std::cout << std::endl;
}
