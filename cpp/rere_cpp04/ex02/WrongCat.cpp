#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), type("WrongCat")
{
	std::cout << "WrongCat default constructor start" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor start" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c)
{
	std::cout << "WrongCat copy constructor start" << std::endl;
	*this = c;
}

WrongCat& WrongCat::operator=(const WrongCat& c)
{
	std::cout << "WrongCat assignation start" << std::endl;
	if (this != &c)
		this->type = c.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << GRN"WrongNyaaan!!!!"RES << std::endl;
}

std::string	WrongCat::getType() const
{
	return (type);
}
