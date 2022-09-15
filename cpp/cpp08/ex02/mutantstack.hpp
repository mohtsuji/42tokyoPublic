#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
//#include <iterator>

template < typename T >
class	MutantStack : public std::stack<T>
{
private:


public:
	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack() { std::cout << "default constructor" << std::endl; }
	~MutantStack() { std::cout << "destructor" << std::endl; }
	MutantStack(const MutantStack<T> &c)
	{
		std::cout << "copy constructor" << std::endl;
		this->c = c.c;
	}

	MutantStack& operator=(const MutantStack<T> &c)
	{
		std::cout << "assignation" << std::endl;
		if (this != &c)
			this->c = c.c;
		return (*this);
	}

	iterator	begin()
	{
		return (this->c.begin());
	}

	const_iterator	begin() const
	{
		return (this->c.begin());
	}

	iterator	end()
	{
		return (this->c.end());
	}

	const_iterator	end() const
	{
		return (this->c.end());
	}

	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator	rbegin() const
	{
		return (this->c.rbegin());
	}

	reverse_iterator	rend()
	{
		return (this->c.rend());
	}

	const_reverse_iterator	rend() const
	{
		return (this->c.rend());
	}

};

#endif
