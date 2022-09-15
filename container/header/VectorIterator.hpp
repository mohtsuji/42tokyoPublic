#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <iostream>
#include <string>
#include <iterator>
#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

template <class T>
class VectorIterator : public ft::iterator<
							typename ft::iterator_traits<T*>::iterator_category,
							typename ft::iterator_traits<T*>::value_type,
							typename ft::iterator_traits<T*>::difference_type,
							typename ft::iterator_traits<T*>::pointer,
							typename ft::iterator_traits<T*>::reference >
{

public:

	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type		value_type;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::pointer			pointer;
	typedef typename ft::iterator_traits<T*>::reference			reference;

/*	typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
*/
	pointer				_pointer;
	pointer				_start; //これもいらないかも
	std::size_t			_idx; //これいらないかも，使ってない

	VectorIterator() : _pointer(NULL), _start(NULL), _idx(0) {}
	~VectorIterator() {}
	VectorIterator(T* t) : _pointer(t), _start(t), _idx(0) {}
	VectorIterator(const VectorIterator &c)
	{
		this->_pointer = c._pointer;
		this->_start = c._start;
		this->_idx = c._idx;
	}
	VectorIterator& operator=(const VectorIterator &c)
	{
		if (this != &c)
		{
			this->_pointer = c._pointer;
			this->_start = c._start;
			this->_idx = c._idx;
		}
		return (*this);
	}

	value_type	&operator*() const { return *_pointer; }
	pointer		operator->() const { return _pointer; }
	value_type	&operator[](std::size_t i) { return (*(_pointer + i)); }

	bool	operator==(const VectorIterator &other) const { return _pointer == other._pointer; }
	bool	operator!=(const VectorIterator &other) const { return _pointer != other._pointer; }
	bool	operator<(const VectorIterator &other) const { return _pointer < other._pointer; }
	bool	operator>(const VectorIterator &other) const { return _pointer > other._pointer; }
	bool	operator<=(const VectorIterator &other) const { return _pointer <= other._pointer; }
	bool	operator>=(const VectorIterator &other) const { return _pointer >= other._pointer; }

	VectorIterator	&operator++() { _pointer++; return (*this); }
	VectorIterator	operator++(int) { VectorIterator ret = *this; _pointer++; return ret; }
	VectorIterator	&operator--() { _pointer--; return (*this); }
	VectorIterator	operator--(int) { VectorIterator ret = *this; _pointer--; return ret; }

	difference_type	operator-(const VectorIterator &other) const { return (_pointer - other._pointer); }

	VectorIterator	operator+(difference_type i) 
	{
		VectorIterator	tmp = *this;
		return (tmp += i);
	}
	VectorIterator	operator-(difference_type i)
	{
		VectorIterator	tmp = *this;
		return (tmp -= i);
	}
	VectorIterator	&operator+=(difference_type i)
	{
		if (i >= 0)
			while (i--)
				++(*this);
		else
			while (i++)
				--(*this);
		return (*this);
	}
	VectorIterator	&operator-=(difference_type i) { return (*this += -i); }

};

template <class T>
VectorIterator<T>	operator+(std::ptrdiff_t i, VectorIterator<T> &v) 
{
	VectorIterator<T>	tmp = v;
	return (tmp += i);
}

template <class T>

class VectorConstIterator : public ft::iterator<
							typename ft::iterator_traits<T*>::iterator_category,
							typename ft::iterator_traits<T*>::value_type,
							typename ft::iterator_traits<T*>::difference_type,
							typename ft::iterator_traits<T*>::pointer,
							typename ft::iterator_traits<T*>::reference >
{

public:

	typedef typename ft::iterator_traits<const T*>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<const T*>::value_type		value_type;
	typedef typename ft::iterator_traits<const T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<const T*>::pointer			pointer;
	typedef typename ft::iterator_traits<const T*>::reference			reference;

	pointer				_pointer;

	VectorConstIterator() : _pointer(NULL) {}
	~VectorConstIterator() {}
	VectorConstIterator(T* t) : _pointer(t) {}
	VectorConstIterator(const VectorConstIterator &c) { this->_pointer = c._pointer; }
	VectorConstIterator(const VectorIterator<T> &c) { this->_pointer = c._pointer; }
	VectorConstIterator& operator=(const VectorConstIterator &c)
	{
		if (this != &c)
			this->_pointer = c._pointer;
		return (*this);
	}
	VectorConstIterator& operator=(const VectorIterator<T> &c)
	{
		this->_pointer = c._pointer;
		return (*this);
	}

	const value_type	&operator*() const { return *_pointer; }
	pointer				operator->() const { return _pointer; }
	const value_type	&operator[](std::size_t i) { return (*(_pointer + i)); }

	bool	operator==(const VectorConstIterator &other) const { return _pointer == other._pointer; }
	bool	operator==(const VectorIterator<T> &other) const { return _pointer == other._pointer; }
	bool	operator!=(const VectorConstIterator &other) const { return _pointer != other._pointer; }
	bool	operator!=(const VectorIterator<T> &other) const { return _pointer != other._pointer; }
	bool	operator<(const VectorConstIterator &other) const { return _pointer < other._pointer; }
	bool	operator<(const VectorIterator<T> &other) const { return _pointer < other._pointer; }
	bool	operator>(const VectorConstIterator &other) const { return _pointer > other._pointer; }
	bool	operator>(const VectorIterator<T> &other) const { return _pointer > other._pointer; }
	bool	operator<=(const VectorConstIterator &other) const { return _pointer <= other._pointer; }
	bool	operator<=(const VectorIterator<T> &other) const { return _pointer <= other._pointer; }
	bool	operator>=(const VectorConstIterator &other) const { return _pointer >= other._pointer; }
	bool	operator>=(const VectorIterator<T> &other) const { return _pointer >= other._pointer; }

	VectorConstIterator	&operator++() { _pointer++; return (*this); }
	VectorConstIterator	operator++(int) { VectorConstIterator ret = *this; _pointer++; return ret; }
	VectorConstIterator	&operator--() { _pointer--; return (*this); }
	VectorConstIterator	operator--(int) { VectorConstIterator ret = *this; _pointer--; return ret; }

	difference_type	operator-(const VectorConstIterator &other) const { return (_pointer - other._pointer); }
	difference_type	operator-(const VectorIterator<T> &other) const { return (_pointer - other._pointer); }

	VectorConstIterator	operator+(difference_type i)
	{
		VectorConstIterator	tmp = *this;
		return (tmp += i);
	}
	VectorConstIterator	operator-(difference_type i)
	{
		VectorConstIterator	tmp = *this;
		return (tmp -= i);
	}
	VectorConstIterator	&operator+=(difference_type i)
	{
		if (i >= 0)
			while (i--)
				++(*this);
		else
			while (i++)
				--(*this);
		return (*this);
	}
	VectorConstIterator	&operator-=(difference_type i) { return (*this += -i); }

};

	template < class T >
	bool	operator==(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer == other._pointer; }

	template < class T >
	bool	operator!=(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer != other._pointer; }

	template < class T >
	bool	operator<(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer < other._pointer; }

	template < class T >
	bool	operator>(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer > other._pointer; }

	template < class T >
	bool	operator<=(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer <= other._pointer; }

	template < class T >
	bool	operator>=(const VectorIterator<T> &target, const VectorConstIterator<T> &other) { return target._pointer >= other._pointer; }

	template < class T >
	std::ptrdiff_t	operator-(const VectorIterator<T> &target , const VectorConstIterator<T> &other) { return (target._pointer - other._pointer); }

	template <class T>
	VectorConstIterator<T>	operator+(std::ptrdiff_t i, VectorConstIterator<T> &v)
	{
		VectorConstIterator<T>	tmp = v;
		return (tmp += i);
	}


};
#endif
