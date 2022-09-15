#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : virtual public ClapTrap {

protected:
	static const unsigned int HP_VAL = 100;
	static const unsigned int EP_VAL = 50;
	static const unsigned int AD_VAL = 20;

public:
	ScavTrap(std::string name);
	ScavTrap(void);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap &copy);

	void attack(std::string const & target);
	void guardGate();

};

#endif
