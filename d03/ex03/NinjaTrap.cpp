
#include "NinjaTrap.hpp"

/*
 * Canonical form
 */

NinjaTrap::NinjaTrap(void) {
	this->_name = "default";
	this->_hp = 60;
	this->_max_hp = 60;
	this->_energy = 120;
	this->_max_energy = 120;
	this->_lvl = 1;
	this->_melee_dmg = 60;
	this->_range_dmg = 5;
	this->_armor = 0;
	this->_range_attack = "Haiaaaaa";
	this->_melee_attack = "Kiaaaaaa";
	std::cout << "NinjaTrap is now at your service "
			  << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) {
	this->_name = name;
	this->_hp = 60;
	this->_max_hp = 60;
	this->_energy = 120;
	this->_max_energy = 120;
	this->_lvl = 1;
	this->_melee_dmg = 60;
	this->_range_dmg = 5;
	this->_armor = 0;
	this->_range_attack = "Haiaaaaa";
	this->_melee_attack = "Kiaaaaaa";
	std::cout << "NinjaTrap is now at your service "
			  << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &other) {
	*this = other;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &rhs) {
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

NinjaTrap::~NinjaTrap() {
	std::cout << "NinjaTrap was fallen " << std::endl;
}


void NinjaTrap::ninjaShoebox(ClapTrap const &target) {
	std::cout << "ClapTrap hitted on Shoebox trap" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const &target) {
	std::cout << "FragTrap hitted on Cherry trap" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const &target) {
	std::cout << "ScavTrap hitted on Sand trap" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const &target) {
	std::cout << "NinjaTrap hitted on Shoebox trap" << std::endl;
}
