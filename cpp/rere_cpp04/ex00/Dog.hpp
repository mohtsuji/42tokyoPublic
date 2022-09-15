#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{

protected:
	std::string	type;

public:
	Dog();
	Dog(const Dog& copy);
	virtual ~Dog();

	Dog& operator=(const Dog& copy);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
