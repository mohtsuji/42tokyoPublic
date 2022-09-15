#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), target("")
{
	Form::setSign(false);
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c)
	: Form(c.getName(), c.getSignGrade(), c.getExecGrade()), target(c.getTarget())
{
	this->setSign(c.getSign());
	std::cout << "ShrubberyCreationForm copy contructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	Form::setSign(false);
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
	std::cout << "ShrubberyCreationForm assignation" << std::endl;
	if (this != &c)
	{
		this->setSign(c.getSign());
		this->target = c.getTarget();
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		Form::execute(executor);

		std::ofstream	ofs;
		std::string		file_name;

		file_name = getTarget() + "_shrubbery";
		ofs.open(file_name, std::ios::app);

		ofs << "       ^       " << std::endl;
		ofs << "     /   \\     " << std::endl;
		ofs << "    /      \\   " << std::endl;
		ofs << "    --------   " << std::endl;
		ofs << "      |  |     " << std::endl;
		ofs << "      ----     " << std::endl;
		ofs.close();
	}
	catch (std::exception & e)
	{
		throw;
	}
}
