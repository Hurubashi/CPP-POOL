
#ifndef ASTEROID_CLASS_HPP
# define ASTEROID_CLASS_HPP

#include "StaticObjectClass.hpp"

class			Asteroid : public StaticObject
{
	public:
		Asteroid(unsigned int x, unsigned int y, char dir, int damage);
		Asteroid(void);
		~Asteroid(void);
		Asteroid(const Asteroid & other);
		Asteroid& operator=(const Asteroid &rhs);
};

#endif
