#include "Char.hpp"

Char::Char()
{
}

Char::~Char()
{
}

Char::Char(std::string str) : Convert(str)
{
}

Char::Char(const Char &c)
{
	*this = c;
}

Char	&Char::operator=(const Char &c)
{
	if (this != &c)
		setStr(c.getStr());
	return (*this);
}

void	Char::toChar()
{
	char		c;
	std::string	s;

	s = getStr();
	if (s.size() == 1)
		c = static_cast<char>(s[0]);
	else
		c = static_cast<char>(s[1]);
	std::cout << "char: " << c;
	std::cout << std::endl;
}

void	Char::toInt()
{
	int			i;
	std::string	s;

	s = getStr();
	if (s.size() == 1)
		i = static_cast<int>(s[0]);
	else
		i = static_cast<int>(s[1]);
	std::cout << "int: " << i;
	std::cout << std::endl;
}

void	Char::toFloat()
{
	float		f;
	std::string	s;

	s = getStr();
	if (s.size() == 1)
		f = static_cast<float>(s[0]);
	else
		f = static_cast<float>(s[1]);
	std::cout << "float: " << f << ".0f";
	std::cout << std::endl;
}

void	Char::toDouble()
{
	double		d;
	std::string	s;

	s = getStr();
	if (s.size() == 1)
		d = static_cast<double>(s[0]);
	else
		d = static_cast<double>(s[1]);
	std::cout << "double: " << d << ".0";
	std::cout << std::endl;
}

