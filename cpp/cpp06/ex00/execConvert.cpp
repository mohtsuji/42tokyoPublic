#include "Convert.hpp"
#include "Char.hpp"
#include "Int.hpp"
#include "Float.hpp"
#include "Double.hpp"

void	charConvert(std::string str)
{
	Char	c(str);

	c.toChar();
	c.toInt();
	c.toFloat();
	c.toDouble();
}

void	intConvert(std::string str)
{
	Int	i(str);

	i.toChar();
	i.toInt();
	i.toFloat();
	i.toDouble();
}

void	floatConvert(std::string str)
{
	Float	f(str);

	f.toChar();
	f.toInt();
	f.toFloat();
	f.toDouble();
}

void	doubleConvert(std::string str)
{
	Double	d(str);

	d.toChar();
	d.toInt();
	d.toFloat();
	d.toDouble();
}

void	scienceConvert(std::string str)
{

	std::cout << "char: " << "impossibe" << std::endl;
	std::cout << "int: " << "impossibe" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		str = str.substr(0, str.size() - 1);
	if (str == "+inf" || str == "+inff")
		str = str.substr(1, str.size());
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}
