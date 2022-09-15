#include "Double.hpp"

Double::Double()
{
}

Double::~Double()
{
}

Double::Double(std::string str) : Convert(str), overflow(false)
{
	d = strtod(str.c_str(), NULL);
	if (d == HUGE_VAL || d == -HUGE_VAL)
		overflow = true;
}

Double::Double(const Double &c)
{
	*this = c;
}

Double	&Double::operator=(const Double &c)
{
	if (this != &c)
	{
		setStr(c.getStr());
		this->d = c.d;
		overflow = c.overflow;
	}
	return (*this);
}

double		Double::getDouble() const
{
	return (d);
}

void	Double::toChar()
{
	char	c;

	if (d < 0 || 127 < d)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(getDouble());
	if (c > 31 && 127 > c)
	{
		std::cout << "char: " << c;
		std::cout << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	Double::toInt()
{
	int		i;
	int	max;
	int	min;

	max = (std::numeric_limits<int>::max());
	min = (std::numeric_limits<int>::min());
	if (max < d || d < min)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	i = static_cast<int>(getDouble());

	std::cout << "int: " << i;
	std::cout << std::endl;
}

void	Double::toFloat()
{
	float	f;

	if (overflow == true || getDouble() > static_cast<double>(std::numeric_limits<float>::max()) || getDouble() < static_cast<double>(std::numeric_limits<float>::min()))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	f = static_cast<double>(getDouble());

	std::cout << "float: " << f << "f";
	std::cout << std::endl;
}

void	Double::toDouble()
{
	if (overflow == true)
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	std::cout << "double: " << d;
	std::cout << std::endl;
}
