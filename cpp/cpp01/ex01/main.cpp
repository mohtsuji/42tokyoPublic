#include "Zombie.hpp"

int	main()
{
	Zombie		*zombie;
	int			N;
	std::string	name;

	std::cout << "please input zombie quantity" << std::endl;
	std::cin >> N;
	std::cout << "please input zombie name" << std::endl;
	std::cin >> name;

	zombie = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}
