#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

template <class Type>
void iter(Type *a, size_t s, void (*f)(const Type &))
{
	for (size_t i = 0; i < s; i++)
	{
		f(a[i]);
	}
}

template <class Type>
void iter(Type *a, size_t s, void (*f)(Type &))
{
	for (size_t i = 0; i < s; i++)
	{
		f(a[i]);
	}
}

template <class Type>
void iter(Type *a, size_t s, void (*f)(const Type))
{
	for (size_t i = 0; i < s; i++)
	{
		f(a[i]);
	}
}
/*
class Awesome {
public:
	Awesome( void ) : _n( 42 ) { return; }

	int get( void ) const { return this->_n; }

private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
*/

#endif
