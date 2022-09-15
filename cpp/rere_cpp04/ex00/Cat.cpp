#include "Cat.hpp"

Cat::Cat() : Animal(), type("Cat")
{
	std::cout << "Cat default constructor start" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor start" << std::endl;
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat copy constructor start" << std::endl;
	*this = c;
}

Cat& Cat::operator=(const Cat& c)
{
	std::cout << "Cat assignation start" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << GRN"Nyaaan!!!!"RES << std::endl;
}

std::string	Cat::getType() const
{
	return (type);
}
