#include "Float.hpp"

Float::Float()
{
}

Float::~Float()
{
}

Float::Float(std::string str) : Convert(str), overflow(false)
{
	d = strtod(str.c_str(), NULL);
	if (d == HUGE_VAL || d == -HUGE_VAL)
		overflow = true;
}

Float::Float(const Float &c)
{
	*this = c;
}

Float	&Float::operator=(const Float &c)
{
	if (this != &c)
	{
		this->d = c.d;
		setStr(c.getStr());
		overflow = c.overflow;
	}
	return (*this);
}

double		Float::getFloat() const
{
	return (d);
}

void	Float::toChar()
{
	char	c;

	if (d < 0 || 127 < d)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(getFloat());
	if (c > 31 && 127 > c)
	{
		std::cout << "char: " << c;
		std::cout << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	Float::toInt()
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
	i = static_cast<int>(getFloat());

	std::cout << "int: " << i;
	std::cout << std::endl;
}

void	Float::toFloat()
{
	float	f;

	if (overflow == true || getFloat() > static_cast<double>(std::numeric_limits<float>::max()) || getFloat() < static_cast<double>(std::numeric_limits<float>::min()))
	{
		std::cout << "float: impossible" << std::endl;;
		return ;
	}

	f = static_cast<float>(getFloat());

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
}

void	Float::toDouble()
{
	if (overflow == true)
	{
		std::cout << "double: impossible" << std::endl;;
		return ;
	}
	std::cout << "double: " << d;
	std::cout << std::endl;
}

