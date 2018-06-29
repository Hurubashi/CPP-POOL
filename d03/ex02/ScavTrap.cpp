
#include "ScavTrap.hpp"

/*
 * Canonical form
 */

ScavTrap::ScavTrap(void) {
	this->_name = "default";
	this->_hp = 100;
	this->_max_hp = 100;
	this->_energy = 50;
	this->_max_energy = 50;
	this->_lvl = 1;
	this->_melee_dmg = 20;
	this->_range_dmg = 15;
	this->_armor = 3;
	this->_range_attack = "Laser Blaster";
	this->_melee_attack = "Kick with a brick";
	std::cout << "ScavTrap is now at your service "
			  << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hp = 100;
	this->_max_hp = 100;
	this->_energy = 50;
	this->_max_energy = 50;
	this->_lvl = 1;
	this->_melee_dmg = 20;
	this->_range_dmg = 15;
	this->_armor = 3;
	this->_range_attack = "Laser Blaster";
	this->_melee_attack = "Kick with a brick";
	std::cout << "ScavTrap is now at your service "
			  << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_max_hp = rhs._max_hp;
	this->_energy = rhs._energy;
	this->_max_energy = rhs._max_energy;
	this->_lvl = rhs._lvl;
	this->_melee_dmg = rhs._melee_dmg;
	this->_range_dmg = rhs._range_dmg;
	this->_armor = rhs._armor;
	return *this;
}

ScavTrap::~ScavTrap() {
		std::cout << "ScavTrap was fallen " << std::endl;
}

std::string		ScavTrap::rand_challenge() {
	std::string style[8];

	static int k = 0;
	k++;
	style[0] = "Вызывает на Смаятупая шутка челендж ";
	style[1] = "Вызывает на невыполнимый СпервогоРазаСкомпилилось челенжд ";
	style[2] = "Вызывает на Самая блестящая лысина челендж ";
	style[3] = "Призывает схватится за что-то. Нужно меньше пить ";
	style[4] = "Хочет померятся длинной функции с ";
	style[5] = "Вызывает на Жри-Взрывайся челендж ";
	style[6] = "Вызывает на Дом-Труба-Шатал челендж ";
	style[7] = "Вызываетна Самый долгий свободный полет без парашута челенж ";
	return (style[(rand() + time(0) + k) % 8]);
}

void	ScavTrap::challengeNewcomer(std::string const &target) {
	if (this->_energy != 0){
		this->_energy -= 25;
		std::cout << "\033[0;32m" << rand_challenge()
				  << target << "\033[0m" << std::endl;
	}
	else
		std::cout << "Not enough energy to use vaulthunter_dot_exe"
				  << target << std::endl;
}
