#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	int	i;

	srand(time(NULL));
	i = rand();

	if (i % 3 == 0)
	{
		A	*a = new A;
		std::cout << "------creata A--------" << std::endl;
		return (a);
	}
	else if (i % 3 == 1)
	{
		B	*b= new B;
		std::cout << "------creata B--------" << std::endl;
		return (b);
	}
	else
	{
		C	*c = new C;
		std::cout << "------creata C--------" << std::endl;
		return (c);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "p* = A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "p* = B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "p* = C" << std::endl;
	else
		std::cout << "I don't know type" << std::endl;
}

void	identify(Base& p)
{
	Base	b;
	try {
		b = dynamic_cast<A&>(p);
		std::cout << "&p = A" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{
	}
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "&p = B" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{
	}
	try {
		b = dynamic_cast<C&>(p);
		std::cout << "&p = C" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{
		std::cout << "I don't know type" << std::endl;
	}
}

int	main()
{
	Base	*b;

	try {
		b = generate();
	}
	catch (std::bad_alloc)
	{
		std::cout << "error malloc" << std::endl;
		return (0);
	}
	identify(b);
	identify(*b);
	delete b;
}
