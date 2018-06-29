
#ifndef STATIC_OBJECT_CLASS
# define STATIC_OBJECT_CLASS

#include "GameObjectClass.hpp"

class			StaticObject : public GameObject
{
	public:
		StaticObject(void);
		~StaticObject(void);
		StaticObject(const StaticObject & other);
		StaticObject& operator=(const StaticObject &rhs);
		StaticObject(unsigned int x, unsigned int y, char dir);

	bool	justFlyInSpace(void);
	int		getDamage(void);

	protected:
		char	_dir;
		int		_damage;
};

#endif