#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"

class AMateria;

class Cure : public AMateria {

public:
	Cure();
	~Cure();

	Cure(const Cure &c);
	Cure& operator=(const Cure& c);

	AMateria* clone() const;
	void use(ICharacter& target);

};



#endif
