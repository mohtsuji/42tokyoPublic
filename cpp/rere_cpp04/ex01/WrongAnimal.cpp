#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor start" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	std::cout << "WrongAnimal copy constructor start" << std::endl;
	*this = c;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor start" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& c)
{
	std::cout << "WrongAnimal assignation start" << std::endl;
	if (&c != this)
		this->type = c.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << GRN"WrongAnimal!!"RES << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}
