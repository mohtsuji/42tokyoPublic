#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"

class MateriaSource : public IMateriaSource {

private:
	AMateria	*m[4];
	int			idx;

public:
	MateriaSource();
	~MateriaSource();

	MateriaSource(const MateriaSource &c);
	MateriaSource& operator=(const MateriaSource &c);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};

#endif
