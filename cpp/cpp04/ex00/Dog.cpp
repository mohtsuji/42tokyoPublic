#include "Dog.hpp"

Dog::Dog() : Animal(), type("Dog")
{
	std::cout << "Dog default constructor start" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor start" << std::endl;
}

Dog::Dog(const Dog &c)
{
	std::cout << "Dog copy constructor start" << std::endl;
	*this = c;
}

Dog& Dog::operator=(const Dog& c)
{
	std::cout << "Dog assignation start" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << GRN"Wann!!!!"RES << std::endl;
}

std::string	Dog::getType() const
{
	return (type);
}
