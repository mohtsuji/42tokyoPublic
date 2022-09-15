#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &c)
{
	static_cast<void>(c);
}

Intern	&Intern::operator=(const Intern &c)
{
	static_cast<void>(c);
	return (*this);
}

Intern::t_formList	Intern::formList[3] =
{
	{"shrubbery create", Intern::createShrubbery},
	{"robotomy request", Intern::createRobotomy},
	{"presidential pardon", Intern::createPresidential}
};

Form	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	Form	*f = NULL;

	try{
		for (int i = 0; i < 3; i++)
		{
			if (formName == formList[i].formName)
				f = formList[i].formType(target);
		}
		if (f == NULL)
			throw Intern::unknownFormName();
	}
	catch (std::exception &e) {
		throw ;
	}
	return (f);
}

Form *Intern::createShrubbery(std::string target)
{
	ShrubberyCreationForm *s = new ShrubberyCreationForm(target);
	std::cout << CYN"Intern create " << s->getName() << RES << std::endl;
	return (s);
}

Form *Intern::createRobotomy(std::string target)
{
	RobotomyRequestForm *r = new RobotomyRequestForm(target);
	std::cout << CYN"Intern create " << r->getName() << RES << std::endl;
	return (r);
}

Form *Intern::createPresidential(std::string target)
{
	PresidentialPardonForm *p = new PresidentialPardonForm(target);
	std::cout << CYN"Intern create " << p->getName() << RES << std::endl;
	return (p);
}

const char *Intern::unknownFormName::what() const throw()
{
	return (GRN"I don't know this Form name."RES);
}
