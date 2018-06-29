
#ifndef SHIP_CLASS_HPP
# define SHIP_CLASS_HPP

//#include "GameObjectClass.hpp"
#include "BulletClass.hpp"

class			Ship : public GameObject
{
	public:
		Ship(void);
		Ship(const Ship & other);
		Ship& operator=(const Ship &rhs);
		~Ship(void);
		Bullet*			shot(void);
		int				getHp(void);
		bool			takeDmg(int num);

	protected:
		char			_shotDir;
		int				_myBulletColor;
		unsigned int	_hp;
};

#endif
