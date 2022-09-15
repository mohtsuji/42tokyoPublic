#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor start" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor start" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain copy constructor start" << std::endl;
	*this = copy;
}

Brain&	Brain::operator=(const Brain& c)
{
	std::cout << "Brain assignation start" << std::endl;
	if (this != &c)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = c.ideas[i];
	}
	return (*this);
}

void	Brain::setIdeas(std::string idea, int lo)
{
	if (lo >= 100)
		std::cout << "lo is too big!!" << std::endl;
	else
		this->ideas[lo] = idea;
}

const std::string&	Brain::getIdeas(int lo) const
{
	if (lo >= 100)
	{
		std::cout << "lo is too big!!" << std::endl;
		return (ideas[lo % 100]);
	}
	else
		return (this->ideas[lo]);
}
