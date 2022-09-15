#include "Character.hpp"

Character::Character() : name(), tmpIdx(0)
{
	for (int i = 0; i < 4; i++)
		m[i] = NULL;
}

Character::Character(const std::string name) : name(name)
{
	tmpIdx = 0;
	for (int i = 0; i < 4; i++)
		m[i] = NULL;
}

Character::Character(const Character& c)
{
	name = c.name;
	for (int i = 0; i < 4; i++)
	{
		if (c.m[i] != NULL)
		{
			m[i] = c.m[i]->clone();
		}
		else
			m[i] = NULL;
	}
	tmpIdx = c.tmpIdx;
}

Character& Character::operator=(const Character& c)
{
	if (this != &c)
	{
		name = c.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->m[i];
			if (c.m[i] != NULL)
			{
				m[i] = c.m[i]->clone();
			}
			else
				m[i] = NULL;
		}
		tmpIdx = c.tmpIdx;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete m[i];
}

std::string const & Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	if (tmpIdx == 4)
		delete m;
	else
	{
		this->m[tmpIdx] = m;
		tmpIdx++;
	}
}

void	Character::unequip(int idx)
{
	if (idx <= 3)
	{
		m[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx <= 3)
	{
		if (m[idx] != NULL)
			m[idx]->use(target);
	}
}
