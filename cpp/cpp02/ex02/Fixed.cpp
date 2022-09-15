#include "Fixed.hpp"

Fixed::Fixed() : fp(0)
{
}

Fixed::Fixed(const Fixed& c)
{
	this->fp = c.getRawBits();
}

Fixed::Fixed(int	num)
{
	this->fp = num << 8;
}

Fixed::Fixed(float	num)
{
	this->fp = (int)(roundf(num * (1 << 8)));
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
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

Fixed&	Fixed::operator=(const Fixed& c)
{
	if (&c != this)
		this->fp = c.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed &target) const
{
	if (this->getRawBits() == target.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &target) const
{
	if (this->getRawBits() != target.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed &target) const
{
	if (this->getRawBits() > target.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &target) const
{
	if (this->getRawBits() >= target.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &target) const
{
	if (this->getRawBits() < target.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &target) const
{
	if (this->getRawBits() <= target.getRawBits())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed &target) const
{
	Fixed	re;

	re.setRawBits(this->getRawBits() + target.getRawBits());
	return (re);
}

Fixed	Fixed::operator-(const Fixed &target) const
{
	Fixed	re;

	re.setRawBits(this->getRawBits() - target.getRawBits());
	return (re);
}

Fixed	Fixed::operator*(const Fixed &target) const
{
	Fixed	re(this->toFloat() * target.toFloat());
	return (re);
}

Fixed	Fixed::operator/(const Fixed &target) const
{
	if (target.toFloat() == 0)
	{
		std::cout << " / 0 is error" << std::endl;
		return (this->toFloat());
	}
	Fixed	re(this->toFloat() / target.toFloat());
	return (re);
}

Fixed&	Fixed::operator++(void)
{
	this->fp++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	re(*this);

	this->fp++;
	return (re);
}

Fixed&	Fixed::operator--(void)
{
	this->fp--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	re(*this);

	this->fp--;
	return (re);
}

const Fixed	&Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one <= two)
		return (one);
	else
		return (two);
}

const Fixed	&Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}

Fixed	&Fixed::min(Fixed& one, Fixed& two)
{
	if (one <= two)
		return (one);
	else
		return (two);
}

Fixed	&Fixed::max(Fixed& one, Fixed& two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}

std::ostream& operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
