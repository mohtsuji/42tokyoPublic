#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-----original test-----" << std::endl;

	Fixed c(3.0f);
	Fixed d(4.2f);
	Fixed e(4.2f);
	const Fixed f(5.6f);
	const Fixed g(2.3f);
	Fixed zero(0.0f);

	std::cout << "c= " << c << std::endl;
	std::cout << "d= " << d << std::endl;
	std::cout << "e= " << e << std::endl;
	std::cout << "f= " << f << std::endl;
	std::cout << "g= " << g << std::endl;

	std::cout << "(d == c)= " << (d == c) << std::endl;
	std::cout << "(d != c)= " << (d != c) << std::endl;
	std::cout << "d < e= " << (d < e) << std::endl;
	std::cout << "d <= e= " << (d <= e) << std::endl;
	std::cout << "d > e= " << (d > e) << std::endl;
	std::cout << "d >= e= " << (d >= e) << std::endl;

	std::cout << "d + c= " << (d + c) << std::endl;
	std::cout << "d - c= " << (d - c) << std::endl;
	std::cout << "c - d= " << (c - d) << std::endl;
	std::cout << "c * d= " << (c * d) << std::endl;
	std::cout << "c / d= " << (c / d) << std::endl;
	std::cout << "zero / d= " << (zero / d) << std::endl;

	std::cout << "c = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "++c = " << ++c << std::endl;

	std::cout << "---------min max---------" << std::endl;
	std::cout << "min(c, d)= " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d)= " << Fixed::max(c, d) << std::endl;
	std::cout << "const min(f, g)= " << Fixed::min(f, g) << std::endl;
	std::cout << "const max(f, g)= " << Fixed::max(f, g) << std::endl;

	std::cout << "---------zero zyosan---------" << std::endl;
	std::cout << "c / zero = " << (c / zero) << std::endl;
	return 0;
}
