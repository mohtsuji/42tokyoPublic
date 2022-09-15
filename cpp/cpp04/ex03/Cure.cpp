#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &c) : AMateria("cure")
{
	*this = c;
}

Cure& Cure::operator=(const Cure &c)
{
	if (this != &c)
	{
		this->type = c.getType();
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria	*newm;

	newm = new Cure();
	return (newm);
}

void	Cure::use(ICharacter& target)
{
	std::cout << RED"* heals " << target.getName() << "’s wounds *"RES;
	std::cout << std::endl;
}
