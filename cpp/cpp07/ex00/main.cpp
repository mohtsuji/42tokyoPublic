#include "whatever.hpp"

#include <string>
#include <iostream>



int	main( void )
{
	int a = 2;
	int b = 3;
	int e = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "-----after swap-----" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl << "----maxで値が同じであったときに，2つ目の引数を返す ----" << std::endl;
	std::cout << "&b = " << &b << ", &e = " << &e << std::endl;
	std::cout << "&(::max( b, e )) = " << &(::max( b, e )) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "\n" << "c = " << c << ", d = " << d << std::endl;

	std::cout << "\n-----after swap-----" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
/*
	std::cout << "\n---------Awesome test-------" << std::endl;

	Awesome	tako(1);
	Awesome	ika(2);

	::swap(tako, ika);
	std::cout << "tako = " << tako.getInt() << std::endl;
	std::cout << "ika = " << ika.getInt() << std::endl;

	std::cout << "min( tako, ika ) = " << ::min( tako, ika ).getInt() << std::endl;
	std::cout << "max( tako, ika ) = " << ::max( tako, ika ).getInt() << std::endl;
*/
	return 0;
}
