
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	FragTrap robot("Gogi");
	ScavTrap scavTrap("Vasya");

	scavTrap.meleeAttack("jojo");
	scavTrap.rangedAttack("Pony");
//	scavTrap.status();
	scavTrap.takeDamage(50);
	scavTrap.takeDamage(30);
	scavTrap.beRepaired(150);
	scavTrap.takeDamage(50);
	scavTrap.takeDamage(40);
	scavTrap.takeDamage(30);
//	scavTrap.status();
	scavTrap.challengeNewcomer("jojo");
	scavTrap.challengeNewcomer("jojo");
	scavTrap.challengeNewcomer("jojo");

//	robot.status();
	robot.rangedAttack("Pasha");
	robot.meleeAttack("Nikolai");
	robot.vaulthunter_dot_exe("Andrey");
	robot.vaulthunter_dot_exe("Andrey");
	robot.vaulthunter_dot_exe("Andrey");
	robot.vaulthunter_dot_exe("Andrey");
	robot.vaulthunter_dot_exe("Andrey");
	robot.takeDamage(20);
	robot.takeDamage(70);
	robot.takeDamage(40);
	robot.takeDamage(40);
	robot.beRepaired(60);
	robot.beRepaired(60);
	robot.beRepaired(60);
//	robot.status();
}