#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), target("")
{
	Form::setSign(false);
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c)
	: Form(c.getName(), c.getSignGrade(), c.getExecGrade()), target(c.getTarget())
{
	this->setSign(c.getSign());
	std::cout << "RobotomyRequestForm copy contructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 72, 45), target(target)
{
	Form::setSign(false);
	std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
	std::cout << "RobotomyRequestForm assignation" << std::endl;
	if (this != &c)
	{
		this->setSign(c.getSign());
		this->target = c.getTarget();
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	this->target = target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try{
		canExec(executor);
		std::cout << CYN"buiiiiiiiiiiiiiiiiiiiiiiii"RES << std::endl;
	
		std::srand(time(NULL));
		if ((rand() % 2) == 0)
			std::cout << CYN << getTarget() << " has been robotomized."RES << std::endl;
		else
			std::cout << CYN << getTarget() << " died."RES << std::endl;
	}
	catch(std::exception &e){
		throw;
	}
}
