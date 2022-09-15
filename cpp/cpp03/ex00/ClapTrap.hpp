#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

private:
	std::string		Name;
	unsigned int	HitPoints;
	unsigned int	Energy;
	unsigned int	Damage;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap(void);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &copy);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
