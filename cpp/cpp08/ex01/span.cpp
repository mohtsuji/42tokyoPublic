#include "span.hpp"

Span::Span() : N(0), p(0)
{
	std::cout << "default constructor start" << std::endl;
}

Span::~Span()
{
	std::cout << "default destructor start" << std::endl;
}

Span::Span(unsigned int n) : N(n), p(0)
{
	std::cout << "constructor start" << std::endl;
}

Span::Span(const Span &c) : N(c.N), s(c.s), p(c.p)
{
	std::cout << "copy constructor start" << std::endl;
}

Span	Span::operator=(const Span &c)
{
	std::cout << "assignation start" << std::endl;
	if (this != &c)
	{
		this->N = c.N;
		this->p = c.p;
		this->s = c.s;
	}
	return (*this);
}

void	Span::addNumber(int i)
{
	if (N == 0)
		throw Span::NoExistPosition();
	else if (p > N - 1)
		throw Span::NoExistPosition();
	s.insert(i);
	p++;
}

unsigned int	Span::shortestSpan()
{
	unsigned int	diff;
	int				before;
	int				now;
	unsigned int	re;

	if ( p == 0)
		throw Span::NoNumbersStored();
	else if ( p == 1)
		throw Span::OnlyOneNumbersStored();
	for (std::multiset<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		before = now;
		now = *i;
		if (i == s.begin())
		{
			re = (unsigned int)INT_MAX - INT_MIN;
			continue ;
		}
		diff = now - before;
		re = std::min(re, diff);
	}
	if (re == 0)
		throw Span::NoSpan();
	return (re);
}

unsigned int	Span::longestSpan()
{
	unsigned int	re;
	int				begin;
	int				end;

	if ( p == 0)
		throw Span::NoNumbersStored();
	else if ( p == 1)
		throw Span::OnlyOneNumbersStored();
	begin = *(s.begin());
	for (std::multiset<int>::iterator i = s.begin(); i != s.end(); i++)
		end = *i;
	re = (unsigned int)end - begin;
	if (re == 0)
		throw Span::NoSpan();
	return (re);
}

const char *Span::NoExistPosition::what() const throw()
{
	return (GRN"Don't set more number"RES);
}

const char *Span::NoNumbersStored::what() const throw()
{
	return (GRN"No numbers storesd"RES);
}

const char *Span::OnlyOneNumbersStored::what() const throw()
{
	return (GRN"Only one numbers stored"RES);
}

const char *Span::NoSpan::what() const throw()
{
	return (GRN"No Span"RES);
}
