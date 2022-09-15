#include "Cat.hpp"

Cat::Cat() : Animal(), type("Cat")
{
	std::cout << "Cat default constructor start" << std::endl;
	catBrain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor start" << std::endl;
	delete catBrain;
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat copy constructor start" << std::endl;
	catBrain = new Brain();
	*this = c;
}

Cat& Cat::operator=(const Cat& c)
{
	std::cout << "Cat assignation start" << std::endl;
	if (this != &c)
	{
		this->type = c.getType();
		*(this->catBrain) = *(c.getBrain());
	}
	return (*this);
}

Animal& Cat::operator=(const Animal& c)
{
	std::cout << "Animal assignation start for Cat" << std::endl;
	if (this != &c)
	{
		this->type = c.getType();
		*(this->catBrain) = *(c.getBrain());
	}
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
Brain*	Cat::getBrain() const
{
	return (catBrain);
}
