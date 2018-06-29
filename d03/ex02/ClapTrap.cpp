
#include "ClapTrap.hpp"

/*
 * Canonical form
 */

ClapTrap::ClapTrap(void) : _name("default"), _hp(0) , _max_hp(0), _energy(0), _max_energy(0),
		  _lvl(0), _melee_dmg(0), _range_dmg(0), _armor(0),
					   _range_attack("none"), _melee_attack("none"){
	std::cout << "ClapTrap is now at your service "
			  << std::endl;
}

ClapTrap::~ClapTrap() {
		std::cout << "ClapTrap was destroyed "
				  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs) {
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

void ClapTrap::rangedAttack(std::string const &target) {
	std::cout << "\033[0;36m" <<  this->_name
			  << " used " << this->_range_attack << " on "
			  << target
			  << ", causing "
			  << this->_range_dmg
			  << " points of damage !\033[0m"
			  << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target) {
	std::cout << "\033[0;36m" <<  this->_name
			  << " used " << this->_melee_attack << " on "
			  << target
			  << ", causing "
			  << this->_melee_dmg
			  << " points of damage !\033[0m"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0) {
		std::cout << "\033[0;31mIt's actually dead. "
				"Stop attacking corpse your fucking freak!\033[0m" << std::endl;
		return ;
	}
	unsigned dmg;
	dmg = amount > this->_armor ? amount - this->_armor : 0;
	this->_hp = this->_hp >= dmg ? this->_hp - dmg : 0;
	if (this->_hp)
	{
		std::cout << "\033[0;31m-" << dmg
				  << " (" << amount << ")"
				  << " dmg taken "
				  << this->_hp << " left\033[0m" << std::endl;
	}
	else if (this->_hp == 0)
	{
		this->_hp = 0;
		std::cout << "\033[0;31m-" << dmg
				  << " (" << amount << ")"
				  << " dmg taken "
				  << this->_hp << " left\033[0m" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp < this->_max_hp)
	{
		unsigned repair;

		repair = this->_hp + amount > this->_max_hp ? amount - (this->_hp + amount) % 100 : amount;
		this->_hp +=repair;
		std::cout << "\033[0;34m+" << repair
				  << " (" << amount << ")"
				  << " hit points repaired. Now have "
				  << this->_hp << " hit points\033[0m" << std::endl;
	}
	else
		std::cout << "\033[0;34m" << "You trying to repair " << amount
				  << " hit points. But there no need, hp is full\033[0m" << std::endl;
}

void	ClapTrap::status() {
	std::cout << std::setw(12) << "name: ";
	std::cout << this->_name << std::endl;
	std::cout << std::setw(12) << "current hp: ";
	std::cout << this->_hp << std::endl;
	std::cout << std::setw(12) << "max hp: ";
	std::cout << this->_max_hp << std::endl;
	std::cout << std::setw(12) << "energy: ";
	std::cout << this->_energy << std::endl;
	std::cout << std::setw(12) << "max energy: ";
	std::cout << this->_max_energy << std::endl;
	std::cout << std::setw(12) << "lvl: ";
	std::cout << this->_lvl << std::endl;
	std::cout << std::setw(12) << "melee dmg: ";
	std::cout << this->_melee_dmg << std::endl;
	std::cout << std::setw(12) << "range dmg: ";
	std::cout << this->_range_dmg << std::endl;
	std::cout << std::setw(12) << "armor: ";
	std::cout << this->_armor << std::endl;
}
