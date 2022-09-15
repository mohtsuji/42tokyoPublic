#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor start" << std::endl;
}

Animal::Animal(const Animal &c)
{
	std::cout << "Animal copy constructor start" << std::endl;
	*this = c;
}

Animal::~Animal()
{
	std::cout << "Animal destructor start" << std::endl;
}

Animal& Animal::operator=(const Animal& c)
{
	std::cout << "Animal assignation start" << std::endl;
	if (&c != this)
		this->type = c.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << GRN"Animal!!"RES << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
