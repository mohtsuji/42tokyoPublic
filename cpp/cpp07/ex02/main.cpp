#include "Array.hpp"

/*__attribute__((destructor))
static void destructor()
{
    system("leaks template");
}*/

int	main()
{
	Array<int>	a;

	std::cout << GRN << "--------default constructor test-----------" << RES << std::endl;
	try {
		std::cout << "a.array = " << a[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "a.size = " << a.size() << std::endl;


	std::cout << GRN << "--------constructor test-----------" << RES << std::endl;
	Array<int>	b(3);
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "b.array = " << b[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "b.size = " << b.size() << std::endl;


	std::cout << GRN << "--------parametor 0 test-----------" << RES << std::endl;
	Array<int>	c(0);
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "c.array = " << c[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "c.size = " << c.size() << std::endl;

	std::cout << GRN << "--------[] writing test-----------" << RES << std::endl;
	Array<int>	d(4);
	try {
		for (int i = 0; i < 4; i++)
		{
			d[i] = i;
			std::cout << "d[i] = " << d[i] << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "d.size = " << d.size() << std::endl;


	std::cout << GRN << "--------const T (const []) test-----------" << RES << std::endl;
	const Array<int>	f(4);
	try {
		for (int i = 0; i < 4; i++)
		{
//			f[i] = i;
			std::cout << "f[i] = " << f[i] << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "f.size = " << f.size() << std::endl;


	std::cout << GRN << "--------string-----------" << RES << std::endl;
	Array<std::string>	s(4);
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "s.array = " << s[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "s.size = " << s.size() << std::endl;

	std::cout << GRN << "--------copy constructor test-----------" << RES << std::endl;

	Array<std::string>	copy = s;
	copy[1] = "copy";
	std::cout << GRN << "--------copy test s-----------" << RES << std::endl;
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "s.array = " << s[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "s.size = " << s.size() << std::endl;
	
	std::cout << GRN << "--------copy test copy-----------" << RES << std::endl;
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "copy.array = " << copy[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "copy.size = " << copy.size() << std::endl;

	std::cout << GRN << "--------assignation test-----------" << RES << std::endl;

	s = copy;
	s[1] = "assignation";
	std::cout << GRN << "--------copy test s-----------" << RES << std::endl;
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "s.array = " << s[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "s.size = " << s.size() << std::endl;
	
	std::cout << GRN << "--------copy test copy-----------" << RES << std::endl;
	try {
		for (int i = 0; i < 4; i++)
			std::cout << "copy.array = " << copy[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	std::cout << "copy.size = " << copy.size() << std::endl;
}
