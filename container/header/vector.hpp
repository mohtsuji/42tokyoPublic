#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <string>
#include  <stdexcept>
#include "iterator.hpp"
#include "VectorIterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft {

template < class T, class Allocator = std::allocator<T> > //Allocatorはstd::allocatorで確定
class	vector
{
public:
	typedef T												value_type;
	typedef Allocator										allocator_type;
	typedef typename std::size_t							size_type;
	typedef typename std::ptrdiff_t							difference_type;
	typedef typename Allocator::reference					reference;
	typedef typename Allocator::const_reference				const_reference;
	typedef typename Allocator::pointer						pointer;
	typedef typename Allocator::const_pointer				const_pointer;
	typedef typename ft::VectorIterator<T>					iterator;
	typedef typename ft::VectorConstIterator<T>				const_iterator;
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

private:
	allocator_type	_a;
	T*				_elem;//要素の先頭
	T*				_space;//予備空間の先頭
	T*				_last;//予備空間の最後の次

public:
	//(1)
	vector() : _a(allocator_type()) , _elem(_a.allocate(0)), _space(_elem), _last(_elem) {}
	//(2) どうやってテストするの？
	explicit vector(const Allocator& alloc) : _a(alloc) , _elem(_a.allocate(0)), _space(_elem), _last(_elem) {}
	//(3)
	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
	{
		_a = alloc;
		_elem = _a.allocate(count);
		_space = _elem + count;
		_last = _elem + count;
		for (size_type i = 0; i < count; i++)
			_a.construct(_elem + i, value);
	}
	//(5)
	template< class InputIt >
	vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL)
	{
		_a = alloc;
		_elem = _a.allocate(last - first);
		_space = _elem + (last - first);
		_last = _elem +(last - first);
		int	i = 0;
		for (InputIt v = first; v != last; v++)
		{
			_a.construct(_elem + i, *v);
			i++;
		}
	}
	//(6) copy constructor
	vector( const vector& other )
	{
		_a = other._a;
		_elem = _a.allocate(other.size());
		_space = _elem + other.size();
		_last = _elem + other.size();
		int	i = 0;
		for (vector::const_iterator v = other.begin(); v != other.end(); v++)
		{
			_a.construct(_elem + i, *v);
			i++;
		}
	}

	~vector()
	{
		size_type size = _space - _elem;
		for (size_type i = 0; i < size; ++i)
			_a.destroy(_elem + i);
		_a.deallocate(_elem, _last - _elem);
	}

	vector& operator=( const vector& other )
	{
		if (this != &other)
		{
			size_type size = _space - _elem;
			for (size_type i = 0; i < size; ++i)
				_a.destroy(_elem + i);
			_a.deallocate(_elem, _last - _elem);
			_a = other._a;
			_elem = _a.allocate(other.size());
			_space = _elem + other.size();
			_last = _elem + other.size();
			int	i = 0;
			for (vector::const_iterator v = other.begin(); v != other.end(); v++)
			{
				_a.construct(_elem + i, *v);
				i++;
			}
		}
		return (*this);
	}
//get_allocator
	allocator_type	get_allocator() const { return _a ; }
//at
	reference		at(size_type pos)
	{
		if (!(pos < size()))
			throw std::out_of_range("vector");
		reference	re = _elem[pos];
		return (re);
	}

	const_reference	at(size_type pos) const
	{
		if (!(pos < size()))
			throw std::out_of_range("vector");
		const_reference	re = _elem[pos];
		return (re);
	}

	reference operator[]( size_type pos )
	{
		reference	re = _elem[pos];
		return (re);
	}

	const_reference operator[]( size_type pos ) const
	{
		const_reference	re = _elem[pos];
		return (re);
	}
//front
	reference front() { return (*_elem); }
	const_reference front() const { return (*_elem); }
//back
	reference back() { return (*(_elem + size() - 1)); }
	const_reference back() const { return (*(_elem + size() - 1));}

//begin
	iterator	begin()
	{
		iterator	re(_elem);
		return (re);
	}

	const_iterator	begin() const
	{
		const_iterator	re(_elem);
		return (re);
	}
//end
	iterator	end()
	{
		iterator	re(_space);
		return (re);
	}

	const_iterator	end() const
	{
		const_iterator	re(_space);
		return (re);
	}

	reverse_iterator	rbegin()
	{
		reverse_iterator	re(_space);
		return (re);
	}

	const_reverse_iterator	rbegin() const
	{
		const_reverse_iterator	re(_space);
		return (re);
	}

	reverse_iterator	rend()
	{
		reverse_iterator	re(_elem);
		return (re);
	}

	const_reverse_iterator	rend() const
	{
		const_reverse_iterator	re(_elem);
		return (re);
	}
//size
	size_type	size() const { return std::distance(begin(), end()); }
//empty
	bool empty() const { return (begin() == end()); }
//max_size https://github.com/google/libcxx/blob/master/include/vector
	size_type max_size() const {
		return (std::min(_a.max_size(), std::numeric_limits<size_type>::max() / 2)); }
//reserve
	void reserve( size_type new_cap )
	{
		if (new_cap > max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		else if (new_cap <= capacity())
			return ;
		T* tmp = _a.allocate(new_cap);
		size_type s = size();
		for (size_type i = 0; i < s; i++)
			tmp[i] = _elem[i];
		for (size_type i = 0; i < s; i++)
			_a.destroy(_elem + i);
		_a.deallocate(_elem, _last - _elem);
		_elem = tmp;
		_space = _elem + s;
		_last = _elem + new_cap;
	}
//capacity
	size_type capacity() const { return (_last - _elem); }
//clear
	void	clear() { _space = _elem; }
//insert
	iterator	insert( iterator pos, const T& value )
	{
		difference_type	diff = pos - begin();
		size_type	oldsize = size();
		size_type	oldcap = capacity();
		if (oldsize == oldcap)
		{
			T*	tmp = _a.allocate(size() * 2);
			iterator	old = begin();
			for (size_type i = 0; i < s + 1; i++)
			{
				if (flag == false && old == pos)
				{
					tmp[i] = value;
					flag = true;
					continue ;
				}
				tmp[i] = *old;
				old++;
			}
			for (size_type i = 0; i < s; i++)
				_a.destroy(_elem + i);
			_a.deallocate(_elem, _last - _elem);
			_elem = tmp;
			_space = _elem + s + 1;
			_last = _elem + s * 2;
		}
		return (begin() + position);
	}

	void insert( iterator pos, size_type count, const T& value );

	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last );
};















};

#endif
