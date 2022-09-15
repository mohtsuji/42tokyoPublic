#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

#include "Form.hpp"

class RobotomyRequestForm : public Form {

private:
	std::string	target;
	RobotomyRequestForm();

public:
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &c);
	RobotomyRequestForm(std::string target);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &c);

	std::string	getTarget() const;
	void		setTarget(std::string target);

	void		execute(Bureaucrat const & executor) const;
};

#endif
