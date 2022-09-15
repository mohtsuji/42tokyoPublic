#include "Form.hpp"

Form::Form() : name(""), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor" << std::endl;
	sign = false;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form::Form(const Form &c) : name(c.getName()), signGrade(c.getSignGrade()), execGrade(c.getExecGrade())
{
	std::cout << "Form copy constructor" << std::endl;
	this->sign = c.getSign();
}

Form::Form(const std::string name, const int signGrade, const int execGrade)
	: name(name), signGrade(signGrade), execGrade(execGrade)
{
	sign = false;
	if (signGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1)
		throw Form::GradeTooHighException();
	if (execGrade > 150)
		throw Form::GradeTooLowException();
	else if (execGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor" << std::endl;
}

Form	&Form::operator=(const Form &c)
{
	std::cout << "Form assignation" << std::endl;
	if (this != &c)
		this->sign = c.getSign();
	return (*this);
}

const std::string	Form::getName() const
{
	return (name);
}

bool				Form::getSign() const
{
	return (sign);
}

int			Form::getSignGrade() const
{
	return (signGrade);
}

int			Form::getExecGrade() const
{
	return (execGrade);
}

void				Form::setSign(bool b)
{
	sign = b;
}

void				Form::beSigned(Bureaucrat &b)
{
	if (getSignGrade() < b.getGrade())
		throw Form::GradeTooLowException();
	else if (sign == true)
		throw Form::AlreadySigned();
	else
		setSign(true);
}

void				Form::execute(Bureaucrat const &b ) const
{
	if (getExecGrade() < b.getGrade())
		throw Form::GradeTooLowException();
	else if (sign == false)
		throw Form::notSigned();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (GRN"Grade too High!!"RES);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (GRN"Grade too Low!!"RES);
}

const char *Form::AlreadySigned::what() const throw()
{
	return (GRN"This Form has already signed!!"RES);
}

const char *Form::notSigned::what() const throw()
{
	return (GRN"This Form don't be signed!!"RES);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "My name is " << f.getName();
	os << ". My signed condition is " << f.getSign();
	os << ". My grade required to sign it is " << f.getSignGrade();
	os << ". My grade required to exec it is " << f.getExecGrade();
	return (os);
}
