#include "Fixed.hpp"

Fixed::Fixed() : fp(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp = c.getRawBits();
}

Fixed::Fixed(int	num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp = num << 8;
}

Fixed::Fixed(float	num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp = (int)(roundf(num * (1 << 8)));
}

Fixed&	Fixed::operator=(const Fixed& c)
{
	std::cout << "Assignation operator called" << std::endl;
	if (&c != this)
	{
		this->fp = c.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp);
}

void	Fixed::setRawBits( int const raw )
{
	this->fp = raw;
}

float Fixed::toFloat( void ) const
{
	float	re;

	re = ((float)this->fp / (float)(1 << 8));
	return (re);
}

int Fixed::toInt( void ) const
{
	int	re;

	re = this->fp / (1 << 8);
	return (re);
}

std::ostream& operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
