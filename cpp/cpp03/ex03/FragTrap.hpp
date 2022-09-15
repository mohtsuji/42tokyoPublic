#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

protected:
	static const unsigned int HP_VAL = 100;
	static const unsigned int EP_VAL = 100;
	static const unsigned int AD_VAL = 30;

public:
	FragTrap(std::string name);
	FragTrap(void);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	FragTrap& operator=(const FragTrap &copy);

	void highFivesGuys(void);
};

#endif
