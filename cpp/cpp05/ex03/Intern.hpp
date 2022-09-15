#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

private:
	static Form	*createShrubbery(std::string target);
	static Form	*createRobotomy(std::string target);
	static Form	*createPresidential(std::string target);

	typedef struct	s_formList
	{
		std::string	formName;
		Form		*(*formType)(std::string);
	}				t_formList;

	static t_formList	formList[3];

public:
	Intern();
	~Intern();
	Intern(const Intern &c);

	Intern &operator=(const Intern &c);

	Form *makeForm(const std::string &formName, const std::string &target);

	class unknownFormName : public std::exception {
		virtual const char * what() const throw();
	};

};

#endif
