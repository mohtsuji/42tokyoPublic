#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {

public:
	ScavTrap(std::string name);
	ScavTrap(void);
	ScavTrap(const ScavTrap &copy);
	virtual ~ScavTrap();

	ScavTrap& operator=(const ScavTrap &copy);

	void attack(std::string const & target);
	void guardGate();

};

#endif
