#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <fstream>

#include "Form.hpp"

class PresidentialPardonForm : public Form {

private:
	std::string	target;
	PresidentialPardonForm();

public:
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &c);
	PresidentialPardonForm(std::string target);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &c);

	std::string	getTarget() const;
	void		setTarget(std::string target);

	void		execute(Bureaucrat const & executor) const;
};

#endif
