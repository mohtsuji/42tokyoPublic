#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {

private:
	std::string	Name;

public:
	DiamondTrap(std::string name);
	DiamondTrap();
	DiamondTrap(const DiamondTrap& copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& copy);

	void attack(std::string const & target);
	void whoAmI();

};

#endif
