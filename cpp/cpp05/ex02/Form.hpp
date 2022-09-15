#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string	name;
	bool				sign;
	const int			signGrade;
	const int			execGrade;
	Form();

protected:
	Form(const Form &c);
	Form(const std::string, const int, const int);

public:
	virtual ~Form();

	virtual Form &operator=(const Form &c);

	const std::string	getName() const;
	bool				getSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void				setSign(bool);

	void				beSigned(Bureaucrat &b);
	virtual void		execute(Bureaucrat const & executor) const  = 0;

	class GradeTooHighException : public std::exception {
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char * what() const throw();
	};

	class AlreadySigned : public std::exception {
		virtual const char * what() const throw();
	};

	class notSigned : public std::exception {
		virtual const char * what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
