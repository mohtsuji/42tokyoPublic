#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BLE "\e[0;35m"
#define RES "\033[m"


class Character : public ICharacter {

private:
	std::string	name;
	AMateria	*m[4];
	int			tmpIdx;

public:
	Character(const std::string name);
	Character(const Character &c);
	~Character();
	Character();

	Character& operator=(const Character &c);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
