#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::zombie_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->zombie_name << " " << "died" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << zombie_name << " " << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}
