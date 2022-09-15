#include <iostream>
#include <string.h>

int	new_error(void)
{
	std::cout << "new_error" << std::endl;
	return (1);
}

int	main()
{
	std::string		s;

	std::string		*stringPTR = &s;
	std::string&	stringREF = s;

	s = "HI THIS IS BRAIN";

	std::cout << "--------s--------\n";
	std::cout << s << std::endl;
	std::cout << "--------stringPTR--------\n";
	std::cout << *stringPTR << std::endl;
	std::cout << "--------stringREF------\n";
	std::cout << stringREF << std::endl;

	std::cout << "--------s--------\n";
	std::cout << &s << std::endl;
	std::cout << "--------stringPTR--------\n";
	std::cout << stringPTR << std::endl;
	std::cout << "--------stringREF------\n";
	std::cout << &stringREF << std::endl;

	return (0);
}
