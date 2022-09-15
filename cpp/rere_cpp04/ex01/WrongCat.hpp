#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

protected:
	std::string	type;

public:
	WrongCat();
	WrongCat(const WrongCat& copy);
	~WrongCat();

	WrongCat& operator=(const WrongCat& copy);

	void		makeSound() const;
	std::string	getType() const;
};

#endif
