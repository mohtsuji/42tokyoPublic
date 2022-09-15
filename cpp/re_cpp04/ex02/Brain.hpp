#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {

private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const Brain& copy);
	virtual ~Brain();

	Brain& operator=(const Brain& copy);
	virtual void				setIdeas(std::string idea, int lo);
	virtual const std::string&	getIdeas(int lo) const;
};


#endif
