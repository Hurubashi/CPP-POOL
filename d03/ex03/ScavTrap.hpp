
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap & other);
	ScavTrap &operator = (const ScavTrap &rhs);
	~ScavTrap(void);
	std::string		rand_challenge();
	void			challengeNewcomer(std::string const & target);
};


#endif
