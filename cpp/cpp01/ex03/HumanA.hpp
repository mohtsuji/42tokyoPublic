#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {

private:
	Weapon		&weapon;
	std::string	name;

public:
	HumanA(std::string name, Weapon &weapon);
	void	attack();
};

#endif
