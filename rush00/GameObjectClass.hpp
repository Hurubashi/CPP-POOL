
#ifndef GAME_OBJECT_CLASS_HPP
# define GAME_OBJECT_CLASS_HPP

#include "MainHeader.hpp"

class				GameObject
{
	public:
		GameObject(void);
		~GameObject(void);
		GameObject(const GameObject & other);
		GameObject& operator=(const GameObject &rhs);
		bool			move(char dir);
		void			draw(WINDOW *win);
		void			clearObject(WINDOW *win);
		int				getX(void);
		int				getY(void);

	protected:
		int				_lastX;
		int				_lastY;
		int				_x;
		int				_y;
		char			_symbol;
		int				_color;
};

#endif
