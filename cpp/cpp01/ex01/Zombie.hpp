#ifndef ZONBIE_H
# define ZONBIE_H

#include <string.h>
#include <iostream>

class Zombie {

private:
	std::string	name;

public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	set_name(std::string name);

};

Zombie*	zombieHorde(int N, std::string name);

#endif
