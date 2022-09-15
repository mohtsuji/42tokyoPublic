#include "Zombie.hpp"

Zombie*	zombieHorde(int N,std::string name)
{
	Zombie	*horde;

	horde = new(std::nothrow) Zombie[N];
	if (horde == NULL)
	{
		std::cout << "new error" << std::endl;
		exit(1);
	}
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}
