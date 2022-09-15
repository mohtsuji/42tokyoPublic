#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"

class WrongAnimal {

protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& copy);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
