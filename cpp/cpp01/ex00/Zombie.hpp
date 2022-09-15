#ifndef ZONBIE_H
# define ZONBIE_H

#include <string.h>
#include <iostream>

class Zombie {

private:
	std::string	zombie_name;

public:
	Zombie(std::string name);
	~Zombie();

	void			announce(void);

};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
