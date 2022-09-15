#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
	std::string type;

public:
	AMateria();
	AMateria(std::string const & type);
	virtual ~AMateria();

	AMateria(const AMateria &c);

	std::string const & getType() const; //Returns the materia type
	void	setType(const std::string &t);
	virtual AMateria& operator=(const AMateria &c);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};


#endif
