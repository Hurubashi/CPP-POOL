
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
 * Canonical form
 */

FragTrap::FragTrap(void) {
	std::cout << "FragTrap is now at your service" << std::endl;
	this->_name = "default";
	this->_hp = 100;
	this->_max_hp = 100;
	this->_energy = 100;
	this->_max_energy = 100;
	this->_lvl = 1;
	this->_melee_dmg = 30;
	this->_range_dmg = 20;
	this->_armor = 5;
	this->_range_attack = "Rocket Launcher";
	this->_melee_attack = "Sword Slash";
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hp = 100;
	this->_max_hp = 100;
	this->_energy = 100;
	this->_max_energy = 100;
	this->_lvl = 1;
	this->_melee_dmg = 30;
	this->_range_dmg = 20;
	this->_armor = 5;
	this->_range_attack = "Rocket Launcher";
	this->_melee_attack = "Sword Slash";
	std::cout << "FragTrap is now at your service "
			  << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
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
FragTrap::~FragTrap() {
		std::cout << "FragTrap was fallen "
				  << std::endl;
}

std::string		FragTrap::rand_attack_style() {
	std::string style[8];

	static int k = 0;
	k++;
	style[0] = "Кидает носком в ";
	style[1] = "Использует магию вуду на ";
	style[2] = "Терзает котят на глазах у ";
	style[3] = "Унизительно смеется с ";
	style[4] = "Громко и не в ноты поет в ухо ";
	style[5] = "(Я использую  Colgate) Испепеляет лучезарной улыбкой ";
	style[6] = "Щекотит на смерть ";
	style[7] = "Пускает в ход свое главное оружие - тупость. Всем жалко ";
	return (style[(rand() + time(0) + k) % 8]);
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target) {
	if (this->_energy != 0){
		this->_energy -= 25;
		std::cout << "\033[0;32m" << rand_attack_style()
				  << target << "\033[0m" << std::endl;
	}
	else
		std::cout << "Not enough energy to use vaulthunter_dot_exe"
				  << target << std::endl;
}
