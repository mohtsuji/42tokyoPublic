#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"

class AMateria;

class Ice : public AMateria {

public:
	Ice();
	~Ice();

	Ice(const Ice &c);
	Ice& operator=(const Ice& c);

	AMateria* clone() const;
	void use(ICharacter& target);

};


#endif
