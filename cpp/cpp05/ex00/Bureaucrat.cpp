#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("")
{
	std::cout << "Burearcrat default constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Burearcrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &c) : name(c.name)
{
	std::cout << "Burearcrat copy constructor" << std::endl;
	*this = c;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	std::cout << "Burearcrat constructor" << std::endl;
	setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
	std::cout << "Burearcrat assignation" << std::endl;
	if (this != &c)
	{
		grade = c.grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

void		Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

void		Bureaucrat::increment()
{
	--(this->grade);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void		Bureaucrat::decrement()
{
	++(this->grade);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (GRN"Grade too High!!"RES);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (GRN"Grade too Low!!"RES);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << "My name is " << b.getName();
	os << ". my grade is " << b.getGrade();
	return (os);
}
