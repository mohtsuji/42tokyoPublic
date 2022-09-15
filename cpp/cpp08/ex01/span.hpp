#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RES "\e[0m"

class Span {

private:
	unsigned int		N;
	std::multiset<int>	s;
	unsigned int		p;
	Span();

public:
	~Span();
	Span(unsigned int n);
	Span(const Span &c);

	Span	operator=(const Span &c);

	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	void			addNumber(int);
	template < typename T >
	void	addNumber(T begin, T end)
	{
		if (N == 0)
			throw Span::NoExistPosition();
		while (begin != end && p < N)
		{
			s.insert(*begin);
			p++;
			begin++;
		}
	}

	class NoExistPosition : public std::exception {
		virtual const char * what() const throw();
	};

	class NoNumbersStored : public std::exception {
		virtual const char * what() const throw();
	};

	class OnlyOneNumbersStored : public std::exception {
		virtual const char * what() const throw();
	};

	class NoSpan : public std::exception {
		virtual const char * what() const throw();
	};

};

#endif
