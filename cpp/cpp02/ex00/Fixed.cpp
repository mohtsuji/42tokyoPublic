#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp = c.getRawBits();
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp);
}

void	Fixed::setRawBits( int const raw )
{
	this->fp = raw;
}
