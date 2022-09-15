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

	Fixed& operator=(const Fixed &copy);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, Fixed const &fixed);

#endif
