#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap(std::string name);
	FragTrap(void);
	FragTrap(const FragTrap &copy);
	virtual ~FragTrap();

	FragTrap& operator=(const FragTrap &copy);

	void highFivesGuys(void);
};

#endif
