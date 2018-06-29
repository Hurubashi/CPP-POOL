
#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "ShipClass.hpp"
#include "BulletClass.hpp"

class			Player : public Ship
{
	public:
		Player(void);
		~Player(void);
		Player(const Player & other);
		Player& operator=(const Player &rhs);
		Player(int up, int right, int left, int down, int shot, int x, int y,
		 int color, int bulletColor, int playerNum);
		
		int		KeyEvent(int ch); /* Она булиан для економии времени на чекании колизий*/
		int		getPlayerNb(void);

	private:
		int				_upB;
		int				_downB;
		int				_leftB;
		int				_rightB;
		int				_shotB;
		int				_playerNum;
};

#endif
