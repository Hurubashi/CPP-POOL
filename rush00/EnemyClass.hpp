
#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "ShipClass.hpp"
#include "BulletClass.hpp"
#include "PlayerClass.hpp"

class			Enemy : public Ship
{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(const Enemy & other);
		Enemy& operator=(const Enemy &rhs);
		Enemy(int x, int y, int color, int bulletColor);

	bool		AI(Player **players, int number_of_players);
};

#endif
