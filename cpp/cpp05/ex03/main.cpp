#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
//OK
	std::cout << std::endl << RED"-------test Intern 11 --------"RES << std::endl;
	try {
		Intern  someRandomIntern;
		Form*   rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat	b("tako", 1);
		std::cout << RED << *rrf << RES << std::endl;
		std::cout << RED << b << RES << std::endl;
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery create", "tako");
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "neko");
		delete rrf;
		rrf = someRandomIntern.makeForm("unknown", "neko");
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
