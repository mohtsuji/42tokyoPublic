#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RES "\e[0m"


template < class T > class Array {

private:
	T				*array;
	unsigned int	s;

public:
	Array() : array(NULL), s(0) {}

	Array(unsigned int n)
	{
		this->s = n;
		array = new T[n]();
	}

	~Array() { delete[] array; }

	Array(const Array<T> &c)
	{
		this->s = c.s;
		if (c.array  == NULL)
			this->array = NULL;
		else
		{
			this->array = new T[c.s];
			for (unsigned int i = 0; i < c.s; i++)
				this->array[i] = c.array[i];
		}
	}

	Array& operator=(const Array<T> &c)
	{
		if (this != &c)
		{
			delete[] this->array;
			this->s = c.s;
			if (c.array  == NULL)
			{
				this->array = NULL;
				return (*this);
			}
			this->array = new T[c.s];
			for (unsigned int i = 0; i < c.s; i++)
			{
				this->array[i] = c.array[i];
			}
		}
		return (*this);
	}

	T				&operator[](unsigned int i)
	{
		if (i >= this->s)
			throw std::out_of_range("out of range");
		else
			return (this->array[i]);
	}

	const T				&operator[](unsigned int i) const
	{
		if (i >= this->s)
			throw std::out_of_range("out of range");
		else
			return (this->array[i]);
	}

	const unsigned int	&size() const { return (this->s); }

};


#endif
