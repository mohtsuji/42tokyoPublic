#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

#include "Brain.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"

class Animal {

protected:
	std::string	type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& copy);
	virtual Brain*		getBrain() const = 0;
	virtual Animal& operator=(const Animal& copy);
	virtual std::string	getType() const;
	virtual void		makeSound() const;
};

#endif
