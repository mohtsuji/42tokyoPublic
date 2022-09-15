#include "iter.hpp"

void	func1(int t)
{
	std::cout << t << std::endl;
}

void	func2(std::string t)
{
	std::cout << t << std::endl;
}

int	main()
{
	int		a[] = {1, 2, 3, 4, 5};

	::iter(a, 5, func1);

	std::string	s[] = {"aaa", "ika", "neko", "tako", "wwaaa"};

	::iter(s, 5, func2);
/*
	std::cout << "\n----review test-------" << std::endl;

	int	tab[] = {0, 1, 2, 3, 4};
	Awesome	tab2[5];

	::iter( tab, 5, print );
	::iter( tab2, 5, print );
*/
	return 0;
}
