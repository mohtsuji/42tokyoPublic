#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "-----grade 151------" <<std::endl;
	try {
		Bureaucrat	b("tako", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----grade ++2------" <<std::endl;
	try {
		Bureaucrat	b("tako", 2);
		std::cout << RED << b << RES << std::endl;
		b.increment();
		std::cout << RED << b << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "-----grade ++1------" <<std::endl;
	try {
		Bureaucrat	b("tako", 1);
		std::cout << RED << b << RES << std::endl;
		b.increment();
		std::cout << RED << b << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----grade --150------" <<std::endl;
	try {
		Bureaucrat	a("neko", 150);
		std::cout << RED << a << RES << std::endl;
		a.decrement();
		std::cout << RED << a << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----grade 149--------" <<std::endl;
	try {
		Bureaucrat	a("neko", 149);
		std::cout << RED << a << RES << std::endl;
		a.decrement();
		std::cout << RED << a << RES << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
