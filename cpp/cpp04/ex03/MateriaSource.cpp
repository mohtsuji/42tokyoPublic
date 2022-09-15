#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		m[i] = NULL;
	idx = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete m[i];
}

MateriaSource::MateriaSource(const MateriaSource &c)
{
	for (int i = 0; i < 4; i++)
	{
		if (c.m[i] != NULL)
		{
			m[i] = c.m[i]->clone();
		}
		else
			m[i] = NULL;
	}
	idx = c.idx;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &c)
{
	if (this != &c)
	{
		for (int i = 0; i < 4; i++)
		{
			delete m[i];
			if (c.m[i] != NULL)
				m[i] = c.m[i]->clone();
			else
				m[i] = NULL;
		}
		idx = c.idx;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (idx == 4)
	{
		delete materia;
		std::cout << GRN"can't learn materia any more"RES << std::endl;
	}
	else
	{
		(m[idx]) = materia;
		idx++;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	if (type == "ice")
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->m[i] != NULL && this->m[i]->getType() == "ice")
				return (this->m[i]->clone());
		}
	}
	else if (type == "cure")
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->m[i] != NULL && this->m[i]->getType() == "cure")
				return (this->m[i]->clone());
		}
	}
	return 0;
}
