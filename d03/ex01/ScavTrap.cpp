
#include "ScavTrap.hpp"

/*
 * Canonical form
 */

ScavTrap::ScavTrap(void)
		: _name("default"), _hp(100) , _max_hp(100), _energy(50), _max_energy(50),
		  _lvl(1), _melee_dmg(20), _range_dmg(15), _armor(3) {
	std::cout << "ScavTrap is now at your service "
			  << std::endl;
}

ScavTrap::ScavTrap(std::string name)
		: _name(name), _hp(100) , _max_hp(100), _energy(50), _max_energy(50),
		  _lvl(1), _melee_dmg(20), _range_dmg(15), _armor(3) {
	std::cout << "ScavTrap is now at your service "
			  << std::endl;
}

ScavTrap::~ScavTrap() {
	static int count = 0;

	count++;
	if ((rand() + time(0) + count) % 5 == 0)
	{
		std::cout << "\033[1;32mWARNING!!!!\033[0m"  << std::endl
				  << "\033[1;35mScavTrap entered EMO-MODE...  " << std::endl
				  << "ScavTrap : You don't care about my feelings at all " << std::endl
				  << "No one loves me in this world... " << std::endl
				  << "self destruction activated... 5.. 4.. 3.. 2.. 1.. \033[0m" << std::endl
				  << "\033[0;31mBoooooommmm\033[0m" << std::endl;
	}
	else
		std::cout << "ScavTrap was fallen "
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

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << "\033[0;36mScavTrap " <<  this->_name
			  << " used Laser shot on "
			  << target
			  << ", causing "
			  << this->_range_dmg
			  << " points of damage !\033[0m"
			  << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) {
	std::cout << "\033[0;36mScavTrap " <<  this->_name
			  << " used Low kick on "
			  << target
			  << ", causing "
			  << this->_melee_dmg
			  << " points of damage !\033[0m"
			  << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hp < 100)
	{
		unsigned repair;

		repair = this->_hp + amount > 100 ? amount - (this->_hp + amount) % 100 : amount;
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
	style[7] = "Вызываетна Самый долгий свободный полет без парашута) челенж ";
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

void	ScavTrap::status() {
	std::cout << std::setw(12) << "name: ";
	std::cout << this->_name << std::endl;
	std::cout << std::setw(12) << "hit points: ";
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