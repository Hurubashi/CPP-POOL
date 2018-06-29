
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap & other);
	ClapTrap &operator = (const ClapTrap &rhs);
	~ClapTrap(void);

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	void			status();

protected:
	std::string		_name;
	unsigned		_hp;
	unsigned		_max_hp;
	unsigned		_energy;
	unsigned		_max_energy;
	unsigned		_lvl;
	unsigned		_melee_dmg;
	unsigned		_range_dmg;
	unsigned		_armor;
	std::string		_range_attack;
	std::string		_melee_attack;
};

#endif
