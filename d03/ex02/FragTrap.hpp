
#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap & other);
	FragTrap &operator = (const FragTrap &rhs);
	~FragTrap(void);
	std::string		rand_attack_style();
	void			vaulthunter_dot_exe(std::string const & target);
};


#endif
