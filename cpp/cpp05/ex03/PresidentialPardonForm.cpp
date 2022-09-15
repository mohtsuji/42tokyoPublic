#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5), target("")
{
	Form::setSign(false);
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c)
	: Form(c.getName(), c.getSignGrade(), c.getExecGrade()), target(c.getTarget())
{
	this->setSign(c.getSign());
	std::cout << "PresidentialPardonForm copy contructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5), target(target)
{
	Form::setSign(false);
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
	std::cout << "PresidentialPardonForm assignation" << std::endl;
	if (this != &c)
	{
		this->setSign(c.getSign());
		this->target = c.getTarget();
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	this->target = target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try{
		canExec(executor);
		std::cout << CYN << getTarget() << " has been pardoned by Zafod Beeblebrox."RES << std::endl;
	}
	catch(std::exception & e){
		throw;
	}
}
