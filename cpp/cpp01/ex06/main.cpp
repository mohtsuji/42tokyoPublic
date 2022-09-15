#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen	karen;

	if (argc != 2)
	{
		std::cerr << "argument error" << std::endl;
		return (1);
	}
	karen.Karen::complain(argv[1]);
	return (0);
}
