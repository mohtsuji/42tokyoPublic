#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

private:
	std::string	target;
	ShrubberyCreationForm();

public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &c);
	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &c);

	std::string	getTarget() const;
	void		setTarget(std::string target);

	void		execute(Bureaucrat const & executor) const;
};

#endif
