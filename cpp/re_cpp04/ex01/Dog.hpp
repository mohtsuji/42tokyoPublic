#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{

private:
	Brain		*dogBrain;

protected:
	std::string	type;

public:
	Dog();
	Dog(const Dog& copy);
	virtual ~Dog();

	Dog& operator=(const Dog& copy);
	Animal& operator=(const Animal& copy);

	void		makeSound() const;
	std::string	getType() const;
	Brain*		getBrain() const;
};

#endif
