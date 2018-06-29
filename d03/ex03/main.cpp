
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int		main(void)
{
	FragTrap fragTrap("Grysha");
	ScavTrap scavTrap("Vasya");
//	ClapTrap clapTrap("Petr");
	NinjaTrap ninja("Tsubaki");

	ninja.ninjaShoebox(scavTrap);
	ninja.ninjaShoebox(fragTrap);
//	ninja.ninjaShoebox(clapTrap);
	ninja.ninjaShoebox(ninja);
	fragTrap.rangedAttack("Mykola");
	fragTrap.takeDamage(20);
	ninja.rangedAttack("Toto");
	scavTrap.meleeAttack("jojo");
	scavTrap.rangedAttack("Pony");
	scavTrap.status();
	scavTrap.takeDamage(50);
	scavTrap.takeDamage(30);
	scavTrap.beRepaired(150);
	scavTrap.takeDamage(50);
	scavTrap.takeDamage(40);
	scavTrap.takeDamage(30);
	scavTrap.challengeNewcomer("jojo");
	scavTrap.challengeNewcomer("jojo");
	scavTrap.challengeNewcomer("jojo");
	scavTrap.status();

	fragTrap.status();
	fragTrap.rangedAttack("Pasha");
	fragTrap.meleeAttack("Nikolai");
	fragTrap.vaulthunter_dot_exe("Andrey");
	fragTrap.vaulthunter_dot_exe("Andrey");
	fragTrap.vaulthunter_dot_exe("Andrey");
	fragTrap.vaulthunter_dot_exe("Andrey");
	fragTrap.vaulthunter_dot_exe("Andrey");
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(70);
	fragTrap.takeDamage(40);
	fragTrap.takeDamage(40);
	fragTrap.beRepaired(60);
	fragTrap.beRepaired(60);
	fragTrap.beRepaired(60);
	fragTrap.status();
}