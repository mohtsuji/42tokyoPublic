#ifndef IMATWRIASOURCE_HPP
# define IMATWRIASOURCE_HPP

#include <string>
#include <iostream>

#include "AMateria.hpp"

class IMateriaSource
{

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
