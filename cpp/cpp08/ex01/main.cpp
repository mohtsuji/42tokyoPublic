#include "span.hpp"
#include <list>

int	main()
{

	std::cout << RED"----shortest empty NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----longest empty NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----shortest only one element NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	sp.addNumber(5);
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----longest only one element NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	sp.addNumber(5);
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----shortest no span NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	sp.addNumber(5);
	sp.addNumber(5);
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----longest no span NG------"RES << std::endl;
	try {
	Span sp = Span(100);
	sp.addNumber(5);
	sp.addNumber(5);
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----addNumber N == 0 NG------"RES << std::endl;
	try {
	Span sp = Span(0);
	sp.addNumber(5);
	sp.addNumber(5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----addNumber OK But no span------"RES << std::endl;
	try {
	Span sp = Span(2);
	sp.addNumber(5);
	sp.addNumber(5);
	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----normal case OK------"RES << std::endl;
	try {
	Span sp = Span(100);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(10);

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----INT max case OK------"RES << std::endl;
	try {
	Span sp = Span(100);

	sp.addNumber(INT_MAX);
	sp.addNumber(INT_MIN);

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"----big case OK------"RES << std::endl;
	try {
	Span sp = Span(10000);

	for (int i = 0; i < 10000; i++)
		sp.addNumber(i);

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << RED"---set iterator vector OK------"RES << std::endl;
	try {
	Span sp = Span(100);
	std::vector<unsigned int>	v(100);
	unsigned int				p = 0;

	for (std::vector<unsigned int>::iterator i = v.begin(); i != v.end(); i++)
		*i = p++;

	sp.addNumber(v.begin(), v.end());

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << RED"---set iterator totyuu made------"RES << std::endl;
	try {
	Span sp = Span(50);
	std::vector<unsigned int>	v(100);
	unsigned int				p = 0;

	for (std::vector<unsigned int>::iterator i = v.begin(); i != v.end(); i++)
		*i = p++;

	sp.addNumber(v.begin(), v.end());

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	{
	std::cout << RED"---set iterator list OK------"RES << std::endl;
	try {
	Span sp = Span(100);
	std::list<unsigned int>	v(100);
	unsigned int				p = 0;

	for (std::list<unsigned int>::iterator i = v.begin(); i != v.end(); i++)
		*i = p++;

	sp.addNumber(v.begin(), v.end());

	std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
}
