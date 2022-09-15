#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

template <class Iter>
class reverse_iterator : public  ft::iterator<
							typename ft::iterator_traits<Iter>::iterator_category,
							typename ft::iterator_traits<Iter>::value_type,
							typename ft::iterator_traits<Iter>::difference_type,
							typename ft::iterator_traits<Iter>::pointer,
							typename ft::iterator_traits<Iter>::reference >
{
public:
	typedef Iter	iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef typename ft::iterator_traits<Iter>::reference			reference;

protected:
	iterator_type	current;

public:
//constructor
	reverse_iterator() : current(iterator_type())  {}
	explicit reverse_iterator( iterator_type it ) : current(it) {}
//copy construtor
	template< class U >
	reverse_iterator( const reverse_iterator<U>& other )
	{
		current = other.current;
	}

//assignation
	template< class U >
	reverse_iterator& operator=( const reverse_iterator<U>& other )
	{
		if (this != &other)
			current = other.base();
		return *this;
	}

	iterator_type	base() const
	{
		iterator_type	re = current;
		return (re);
	}

	reference	operator*() const
	{
		iterator_type	tmp = current;
		return (*--tmp);
	}

	pointer operator->() const
	{
		pointer	tmp = &(*current);
		return (--tmp);
	}

	value_type	&operator[]( difference_type n ) const { return ((this->base()[-n-1]));};

	reverse_iterator& operator++() { current--; return *(this); }
	reverse_iterator& operator--() { current++; return *(this); }
	reverse_iterator operator++( int ) { reverse_iterator ret = *this; current--; return ret; }
	reverse_iterator operator--( int ) { reverse_iterator ret = *this; current++; return ret; }
	reverse_iterator operator-( difference_type n ) const
	{
		reverse_iterator	tmp = *this;
		return (tmp -= n);
	}
	reverse_iterator operator+( difference_type n ) const
	{
		reverse_iterator	tmp = *this;
		return (tmp += n);
	}
	reverse_iterator& operator+=( difference_type n )
	{
		return (*this -= -n);
	}
	reverse_iterator& operator-=( difference_type n )
	{
		if (n >= 0)
			while (n--)
				++current;
		else
			while (n++)
				--current;
		return (*this);
	}
};

template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() == rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() != rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() > rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() >= rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() < rhs.base()); }

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{ return (lhs.base() <= rhs.base()); }

template< class Iter >
reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{
	reverse_iterator<Iter>	tmp = it;
	return (tmp += n);
}

template< class Iter >
typename reverse_iterator<Iter>::difference_type operator-( const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs )
{
	return (rhs.base() - lhs.base());
}


};

#endif
