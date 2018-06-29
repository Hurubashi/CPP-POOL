
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "FragTrap.hpp"

class ScavTrap{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & other);
	ScavTrap &operator = (const ScavTrap &rhs);
	~ScavTrap(void);

	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		rand_challenge();
	void			challengeNewcomer(std::string const & target);
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
