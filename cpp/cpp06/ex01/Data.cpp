#include "Data.hpp"

Data::Data()
{
}

Data::Data(int i)
{
	this->i = i;
}

Data::~Data()
{
}

Data::Data(const Data &c)
{
	*this = c;
}

Data&	Data::operator=(const Data &c)
{
	if (this != &c)
	{
		this->i = c.i;
	}
	return (*this);
}

int		Data::getInt() const
{
	return (i);
}
