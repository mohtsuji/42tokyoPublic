#include "Zombie.hpp"

int	main()
{
	std::cout << "-----newZombie name please(test newZombie)----" << std::endl;
	{
		std::string	new_name;
		Zombie		*new_zombie;

		std::cin >> new_name;
		new_zombie = newZombie(new_name);
		if (new_zombie == NULL)
		{
			std::cout << "new error" << std::endl;
			return (1);
		}
		new_zombie->announce();
		delete (new_zombie);
	}

	std::cout << "-----newZombie name please(test ramdomChamp)----" << std::endl;
	{
		std::string	new_name;

		std::cin >> new_name;
		randomChump(new_name);
	}
	return (0);
}
