#include "Convert.hpp"

Convert::Convert()
{
}

Convert::~Convert()
{
}

Convert::Convert(std::string str) : str(str), type("")
{
}

Convert::Convert(const Convert &c)
{
	*this = c;
}

Convert	&Convert::operator=(const Convert &c)
{
	if (this != &c)
	{
		this->str = c.getStr();
		this->str = c.getType();
	}
	return (*this);
}

std::string	Convert::getStr() const
{
	return (str);
}

void		Convert::setStr(std::string str)
{
	this->str = str;
}

std::string	Convert::getType() const
{
	return (type);
}

void		Convert::setType(std::string type)
{
	this->type = type;
}
