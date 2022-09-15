#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{

	try {
		Form	f("tako", 0, 1);
		std::cout << RED << f << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("neko", 151, 1);
		std::cout << RED << f << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("tako", 1, 0);
		std::cout << RED << f << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form	f("neko", 150, 199);
		std::cout << RED << f << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------- OK -------------" << std::endl;
	try {
		Form	f("form", 150, 150);
		Bureaucrat	b("tako", 1);
		std::cout << RED << f << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//OK
	std::cout << "----------- OK -------------" << std::endl;
	try {
		Form	f("form", 150, 150);
		Bureaucrat	b("neko", 150);
		std::cout << RED << f << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
//NG
	std::cout << "----------- NG -------------" << std::endl;
	try {
		Form	f("form", 1, 1);
		Bureaucrat	b("neko", 150);
		std::cout << RED << f << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
