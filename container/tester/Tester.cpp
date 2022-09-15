#include "Tester.hpp"

Tester::Tester()
{}

Tester::~Tester()
{}

Tester::Tester(const Tester &c)
{}

Tester& Tester::operator=(const Tester &c)
{
	return (*this);
}

void	Tester::btitle(std::string s)
{
	std::cout << RED << "============== " << s << " ================" << RES << std::endl;
}

void	Tester::title(std::string s)
{
	std::cout << GRN << s << RES << std::endl;
}
/*
void	Tester::comp(std::stringstream &s, std::stringstream &f)
{
	std::string	std;
	std::string	ft;

	s >> std;
	f >> ft;

	if (std == ft)
	{
		std::cout << "std = " << std << std::endl;
		std::cout << "ft  = " << ft << std::endl;
		std::cout << CYN << "OK" << RES << std::endl;
	}
	else
	{
		std::cout << "std = " << std << std::endl;
		std::cout << "ft  = " << ft << std::endl;
		std::cout << RED << "NG" << RES << std::endl;
		exit(1);
	}
}

void	Tester::comp(const int &s, const int &f)
{
	if (s == f)
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << CYN << "OK" << RES << std::endl;
	}
	else
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << RED << "NG" << RES << std::endl;
		exit(1);
	}
}

void	Tester::comp(const bool s, const bool f)
{
	if (s == f)
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << CYN << "OK" << RES << std::endl;
	}
	else
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << RED << "NG" << RES << std::endl;
		exit(1);
	}
}

void	Tester::comp(const std::ptrdiff_t s, const std::ptrdiff_t f)
{
	if (s == f)
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << CYN << "OK" << RES << std::endl;
	}
	else
	{
		std::cout << "std = " << s << std::endl;
		std::cout << "ft  = " << f << std::endl;
		std::cout << RED << "NG" << RES << std::endl;
		exit(1);
	}
}
*/
/*
void	Tester::comp(std::vector<T>::iterator &s, ft::vector<T>iterator &f)
{
	if (s == f)
		std::cout << CYN << "OK" << RES << std::endl;
	else
	{
		std::cout << RED << "std = " << s << RES << std::endl;
		std::cout << RED << "ft  = " << f << RES << std::endl;
	}
}
*/
