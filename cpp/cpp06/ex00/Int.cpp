#include "Int.hpp"

Int::Int()
{
}

Int::~Int()
{
}

Int::Int(std::string str) : Convert(str)
{
	std::string	s;
	long		ans;
	bool		negative = false;
	int			j;

	s = str;
	ans = 0;
	j = 0;
	if (s[0] == '0' && s.size() != 1)
	{
		std::cout << "int invalid value" << std::endl;
		exit(1);
	}
	if (s[j] == '-')
	{
		negative = true;
		j++;
		if (s[j] == '0')
		{
			std::cout << "int invalid value" << std::endl;
			exit(1);
		}
	}
	while (s[j])
	{
		ans = ans * 10 + (s[j] - '0');
		if (ans > 2147483647)
		{
			std::cout << "int overflow" << std::endl;
			exit(1);
		}
		++j;
	}
	if (negative == true)
		ans = ans * -1;
	this->i = static_cast<int>(ans);
}

Int::Int(const Int &c)
{
	*this = c;
}

Int	&Int::operator=(const Int &c)
{
	if (this != &c)
		setStr(c.getStr());
	return (*this);
}

int		Int::getInt() const
{
	return (i);
}

void	Int::toChar()
{
	char	c;

	if (getInt() < 0 || 127 < getInt())
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (getInt() <= 31 || 127 <= getInt())
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	c = static_cast<char>(i);
	std::cout << "char: " << c;
	std::cout << std::endl;
}

void	Int::toInt()
{
	std::cout << "int: " << i;
	std::cout << std::endl;
}

void	Int::toFloat()
{
	float		f;

	f = static_cast<float>(getInt());
	std::cout << "float: " << f << ".0f";
	std::cout << std::endl;
}

void	Int::toDouble()
{
	double		d;

	d = static_cast<double>(i);
	std::cout << "double: " << d << ".0";
	std::cout << std::endl;
}
