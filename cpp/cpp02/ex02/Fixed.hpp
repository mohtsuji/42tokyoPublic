#ifndef FIXED_H
# define FIXED_H

#include <string.h>
#include <iostream>
#include <cmath>



class	Fixed {

private:
	int					fp;
	static const int	fbit = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(int	num);
	Fixed(float	num);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=(const Fixed &copy);

	bool	operator==(const Fixed &target) const ;
	bool	operator!=(const Fixed &target) const ;
	bool	operator>(const Fixed &target) const ;
	bool	operator>=(const Fixed &target) const ;
	bool	operator<(const Fixed &target) const ;
	bool	operator<=(const Fixed &target) const ;

	Fixed	operator+(const Fixed &target) const ;
	Fixed	operator-(const Fixed &target) const ;
	Fixed	operator*(const Fixed &target) const ;
	Fixed	operator/(const Fixed &target) const ;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static const Fixed	&min(const Fixed& one, const Fixed& two);
	static const Fixed	&max(const Fixed& one, const Fixed& two);
	static Fixed	&min(Fixed& one, Fixed& two);
	static Fixed	&max(Fixed& one, Fixed& two);
};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

#endif
