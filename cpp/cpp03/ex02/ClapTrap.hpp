#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

protected:
	std::string		Name;
	unsigned int	HitPoints;
	unsigned int	Energy;
	unsigned int	Damage;

public:
	ClapTrap(std::string name);
	ClapTrap(void);
	ClapTrap(const ClapTrap &copy);
	virtual ~ClapTrap();

	ClapTrap& operator=(const ClapTrap &copy);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	unsigned int GetHitPoints() const;
	unsigned int GetEnergy() const;
	unsigned int GetDamage() const;

	void SetHitPoints(unsigned int hitpoints);
	void SetEnergy(unsigned int energy);
	void SetDamage(unsigned int damage);
};

#endif
