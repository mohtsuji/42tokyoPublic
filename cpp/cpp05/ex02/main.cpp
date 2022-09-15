#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
//OK
	std::cout << std::endl << RED"-------test 1 OK --------"RES << std::endl;
	try {
		ShrubberyCreationForm	s("ika");
		Bureaucrat	b("tako", 1);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(s);
		b.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 2 NG --------"RES << std::endl;
	try {
		ShrubberyCreationForm	s("ika");
		Bureaucrat	b("tako", 150);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(s);
		b.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 3 NG --------"RES << std::endl;
	try {
		ShrubberyCreationForm	s("ika");
		Bureaucrat	t("tako", 150);
		Bureaucrat	n("neko", 1);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << t << RES << std::endl;
		std::cout << RED << n << RES << std::endl;
		t.signForm(s);
		n.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 4 NG --------"RES << std::endl;
	try {
		ShrubberyCreationForm	s("ika");
		Bureaucrat	t("tako", 1);
		Bureaucrat	n("neko", 150);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << t << RES << std::endl;
		std::cout << RED << n << RES << std::endl;
		t.signForm(s);
		n.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//OK
	std::cout << std::endl << RED"-------test 5 OK --------"RES << std::endl;
	try {
		RobotomyRequestForm	r("ika");
		Bureaucrat	b("tako", 1);
		std::cout << RED << r << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(r);
		b.executeForm(r);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 6 NG --------"RES << std::endl;
	try {
		RobotomyRequestForm	s("ika");
		Bureaucrat	b("tako", 150);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(s);
		b.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 7 NG --------"RES << std::endl;
	try {
		RobotomyRequestForm	s("ika");
		Bureaucrat	t("tako", 73);
		Bureaucrat	n("neko", 1);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << t << RES << std::endl;
		std::cout << RED << n << RES << std::endl;
		t.signForm(s);
		n.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//OK
	std::cout << std::endl << RED"-------test 8 OK --------"RES << std::endl;
	try {
		PresidentialPardonForm	r("ika");
		Bureaucrat	b("tako", 1);
		std::cout << RED << r << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(r);
		b.executeForm(r);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 9 NG --------"RES << std::endl;
	try {
		PresidentialPardonForm	s("ika");
		Bureaucrat	b("tako", 150);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(s);
		b.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << std::endl << RED"-------test 10 NG --------"RES << std::endl;
	try {
		PresidentialPardonForm	s("ika");
		Bureaucrat	t("tako", 150);
		Bureaucrat	n("neko", 1);
		std::cout << RED << s << RES << std::endl;
		std::cout << RED << t << RES << std::endl;
		std::cout << RED << n << RES << std::endl;
		t.signForm(s);
		n.executeForm(s);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
