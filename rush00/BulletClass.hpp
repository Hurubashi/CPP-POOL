
#ifndef BULLET_CLASS_HPP
# define BULLET_CLASS_HPP

#include "StaticObjectClass.hpp"

class			Bullet : public StaticObject
{
	public:
		Bullet(void);
		~Bullet(void);
		Bullet(const Bullet & other);
		Bullet& operator=(const Bullet &rhs);
		Bullet(unsigned int x, unsigned int y, char dir, int damage, int color);
};

#endif