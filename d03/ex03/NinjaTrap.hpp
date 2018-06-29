
#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {

public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap & other);
	NinjaTrap &operator = (const NinjaTrap &rhs);
	~NinjaTrap();

	void			ninjaShoebox(ScavTrap const &target);
	void			ninjaShoebox(FragTrap const &target);
	void			ninjaShoebox(NinjaTrap const &target);
	void			ninjaShoebox(ClapTrap const &target);
};


#endif
