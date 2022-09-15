#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	dia("ika");

	dia.attack("neko");
	dia.takeDamage(4);
	dia.beRepaired(10);
	dia.highFivesGuys();
	dia.whoAmI();
	dia.guardGate();
}
