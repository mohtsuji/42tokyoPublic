#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	scav("neko");

	scav.attack("ika");
	scav.takeDamage(4);
	scav.beRepaired(10);
	scav.guardGate();
}
