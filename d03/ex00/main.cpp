
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap robot;
//	FragTrap robot2("Kiril");

//	robot2 = robot;
//	robot.say();
//	robot2.say();
	robot.status();
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
	robot.status();

}