#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RES "\e[0m"

class Bureaucrat {

private:
	const std::string	name;
	int			grade;
	Bureaucrat();

public:
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &c);

	Bureaucrat &operator=(const Bureaucrat &c);

	std::string	getName() const;
	int			getGrade() const;
	void		setGrade(int grade);

	void		increment();
	void		decrement();

	class GradeTooHighException : public std::exception {
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char * what() const throw();
	};


};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);


#endif
