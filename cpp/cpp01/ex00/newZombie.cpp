#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*newz;

	newz = new(std::nothrow) Zombie(name);
	return (newz);
}
