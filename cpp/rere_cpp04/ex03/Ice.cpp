#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &c) : AMateria("ice")
{
	*this = c;
}

Ice& Ice::operator=(const Ice &c)
{
	if (this != &c)
		this->type = c.getType();
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria	*newm;

	newm = new Ice();
	return (newm);
}

void	Ice::use(ICharacter& target)
{
	std::cout << RED"* shoots an ice bolt at ";
	std::cout << target.getName();
	std::cout << " *"RES << std::endl;
}
