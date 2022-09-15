#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>

template < class Type >
void swap(Type &a, Type &b)
{
	Type	t = a;

	a = b;
	b = t;
}

template < class Type >
const Type& min(const Type &a,  const Type &b)
{
	if (a == b || a > b)
		return (b);
	else
		return (a);
}

template < class Type >
const Type& max(const Type &a, const Type &b)
{
	if (a == b || a < b)
		return (b);
	else
		return (a);
}
/*
class	Awesome {
public:
	Awesome( int n ) : _n( n ) {}

	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

	int	getInt() const {
		return (_n);
	}

private:
	int _n;
};
*/
#endif
