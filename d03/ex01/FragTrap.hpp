
#ifndef FRAGTRAP_H
#define FRAGTRAP_H


#include <string>
#include <iostream>
#include <iomanip>

class FragTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap & other);
	FragTrap &operator = (const FragTrap &rhs);
	~FragTrap(void);

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		rand_attack_style();
	void			vaulthunter_dot_exe(std::string const & target);
	void			status();

private:
	std::string		_name;
	unsigned		_hp;
	unsigned		_max_hp;
	unsigned		_energy;
	unsigned		_max_energy;
	unsigned		_lvl;
	unsigned		_melee_dmg;
	unsigned		_range_dmg;
	unsigned		_armor;
};


#endif
