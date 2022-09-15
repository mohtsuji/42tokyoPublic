#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " " << "died" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << " " << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}
