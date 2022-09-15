#include "Karen.hpp"

int	main()
{
	Karen	karen;

	std::cout << RED"----debug----"RES << std::endl;
	karen.Karen::complain("debug");
	std::cout << RED"----info----"RES << std::endl;
	karen.Karen::complain("info");
	std::cout << RED"----warning----"RES << std::endl;
	karen.Karen::complain("warning");
	std::cout << RED"----error----"RES << std::endl;
	karen.Karen::complain("error");
	std::cout << RED"----else----"RES << std::endl;
	karen.Karen::complain("else");
}
