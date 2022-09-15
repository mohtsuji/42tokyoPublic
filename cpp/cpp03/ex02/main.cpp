#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	frag("ika");

	frag.attack("neko");
	frag.takeDamage(4);
	frag.beRepaired(10);
	frag.highFivesGuys();
}
