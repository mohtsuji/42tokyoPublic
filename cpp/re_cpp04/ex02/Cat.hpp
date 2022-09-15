#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

private:
	Brain		*catBrain;

protected:
	std::string	type;

public:
	Cat();
	Cat(const Cat& copy);
	virtual ~Cat();

	Cat& operator=(const Cat& copy);
	Animal& operator=(const Animal& copy);

	void		makeSound() const;
	std::string	getType() const;
	Brain*		getBrain() const;
};

#endif
