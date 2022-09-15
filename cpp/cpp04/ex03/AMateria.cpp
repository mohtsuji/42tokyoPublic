#include "AMateria.hpp"

AMateria::AMateria() : type()
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &c)
{
	*this = c;
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::setType(const std::string &t)
{
	this->type = t;
}

AMateria& AMateria::operator=(const AMateria& c)
{
	if (this != &c)
		this->type = c.type;
	return (*this);
}
