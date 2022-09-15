#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{

protected:
	std::string	type;

public:
	Cat();
	Cat(const Cat& copy);
	virtual ~Cat();

	Cat& operator=(const Cat& copy);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
