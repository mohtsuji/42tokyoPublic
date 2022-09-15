#include "Dog.hpp"

Dog::Dog() : Animal(), type("Dog")
{
	std::cout << "Dog default constructor start" << std::endl;
	dogBrain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor start" << std::endl;
	delete dogBrain;
}

Dog::Dog(const Dog &c)
{
	std::cout << "Dog copy constructor start" << std::endl;
	dogBrain = new Brain();
	*this = c;
}

Dog& Dog::operator=(const Dog& c)
{
	std::cout << "Dog assignation start" << std::endl;
	if (this != &c)
	{
		this->type = c.getType();
		*(this->dogBrain) = *(c.getBrain());
	}
	return (*this);
}

Animal& Dog::operator=(const Animal& c)
{
	std::cout << "Animal assignation start for Dog" << std::endl;
	if (this != &c)
	{
		this->type = c.getType();
		*(this->dogBrain) = *(c.getBrain());
	}
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

Brain*	Dog::getBrain() const
{
	return (dogBrain);
}
