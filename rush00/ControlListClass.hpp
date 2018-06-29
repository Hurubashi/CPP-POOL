
#ifndef CHAINEDLISTCLASS_HPP
#define CHAINEDLISTCLASS_HPP

#include "MainHeader.hpp"
#include "PlayerClass.hpp"
#include "EnemyClass.hpp"
#include "StaticObjectClass.hpp"

class ControlListClass {

	typedef struct s_static {
		StaticObject	*el;
		s_static		*next;
	}				t_static;

	typedef struct s_enemies {
		Enemy		*el;
		s_enemies	*next;
	}				t_enemies;

public:
	ControlListClass();
	ControlListClass(const ControlListClass & other);
	ControlListClass& operator=(const ControlListClass &rhs);
	~ControlListClass();

	/*			Our push back functions			*/
	void		pushBack(Enemy *);
	void		pushBack(StaticObject *);
	/*			Our cleat function				*/
	void		clearOne(int index, std::string type, WINDOW *win);
	void		clearAll(WINDOW *win);
	/*			Draw all onjects				*/
	void		drawAll(WINDOW *win);
	/*			For Static Objects				*/
	void		moveAllStatic(WINDOW *win, Player **players, int *n_of_players);
	void		someAI(WINDOW *win, Player **players, int *n_of_players);
	bool		CheckCollisionForList(WINDOW *win,int *index_s, int *index_e, int x, int y, std::string type);
	int			getNumStatic(void);
	int			getNumEnemies(void);

private:
	void			_clearAllEnemies(WINDOW *win);
	void			_clearAllStatics(WINDOW *win);
	void			_clearEnemy(int index, WINDOW *win);
	void			_clearStatic(int index, WINDOW *win);
	int				_nEnemy;
	int				_nStatic;
	t_static		*_staticStart;
	t_enemies		*_enemiesStart;


};


#endif
