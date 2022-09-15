#include <string>
#include <sstream>
#include <iostream>

#include "Convert.hpp"
#include "Char.hpp"
#include "Int.hpp"
#include "Float.hpp"
#include "Double.hpp"

void	charConvert(std::string str);
void	intConvert(std::string str);
void	floatConvert(std::string str);
void	doubleConvert(std::string str);
void	scienceConvert(std::string str);

int	put_error(std::string message)
{
	std::cout << message << std::endl;
	return (1);
}

std::string	typeSelect(std::string str)
{
	bool	isDot = false;
	bool	isF = false;

	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
		return ("science");
	if (str.size() == 1)
	{
		if ('0' <= str[0] && str[0] <= '9')
			return ("int");
		else
			return ("char");
	}
	if (str[0] == '\'')
	{
		if (str.size() == 3 && str[str.size() - 1] == '\'')
			return ("char");
		else
			return ("false");
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue ;
		if ((str[i] < '0' || '9' < str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != 'F')
			return ("false");
		if (str[i] == '.')
		{
			if (isDot == true)
				return ("false");
			isDot = true;
		}
		if (str[i] == 'f' || str[i] == 'F')
		{
			if (i != (str.size() - 1) || i == 0 || isDot == false)
				return ("false");
			isF = true;
		}
	}
	if (isF == true)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if ('0' <= str[i] && str[i] <= '9')
				return ("float");
		}
		return ("false");
	}
	else if (isDot == true)
		return ("double");
	return ("int");
}

int	main(int argc, char **argv)
{
	std::string			type;

	if (argc != 2)
		return (put_error("argc error"));
	type = typeSelect(argv[1]);
	if (type == "false")
		return (put_error("illegal string"));

	if (type == "science")
		scienceConvert(argv[1]);
	else if (type == "char")
		charConvert(argv[1]);
	else if (type == "int")
		intConvert(argv[1]);
	else if (type == "float")
		floatConvert(argv[1]);
	else
		doubleConvert(argv[1]);
}
