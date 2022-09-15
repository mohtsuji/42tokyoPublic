#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	*newz;

	newz = new(std::nothrow) Zombie(name);
	if (newz == NULL)
	{
		std::cout << "new error" << std::endl;
		exit(1);
	}
	newz->announce();
	delete (newz);
}
