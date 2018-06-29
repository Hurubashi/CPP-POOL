
#include "ControlListClass.hpp"

ControlListClass::ControlListClass() {
	this->_staticStart = NULL;
	this->_enemiesStart = NULL;
	this->_nEnemy = 0;
	this->_nStatic = 0;
}

ControlListClass::ControlListClass(const ControlListClass &other) {*this = other;}

ControlListClass& ControlListClass::operator=(const ControlListClass &copy) {
	this->_nEnemy = copy._nEnemy;
	this->_nStatic = copy._nStatic;
	this->_staticStart = copy._staticStart;
	this->_enemiesStart = copy._enemiesStart;
	return *this;
}

ControlListClass::~ControlListClass() {}

void	ControlListClass::clearOne(int index, std::string type, WINDOW *win) {
	if (type == "Static") {
		this->_clearStatic(index, win);
	}
	else
		this->_clearEnemy(index, win);
}

void	ControlListClass::_clearEnemy(int index, WINDOW *win) {
	t_enemies	*list;
	t_enemies	*parent;
	t_enemies	*tmp;
	int			i = 0;

	list = this->_enemiesStart;
	if (index == 0) {
		this->_enemiesStart->el->clearObject(win);
		delete this->_enemiesStart->el;
		this->_enemiesStart = this->_enemiesStart->next;
		delete list;
	} else {
		while (list && i < index - 1) {
			list = list->next;
			i++;
		}
		tmp = list;
		list = list->next;
		tmp->next = list->next;
		list->el->clearObject(win);
		delete list->el;
		delete list;
	}
	this->_nEnemy--;
}

void	ControlListClass::_clearStatic(int index, WINDOW *win) {
	t_static	*list;
	t_static	*parent;
	t_static	*tmp;
	int			i = 0;

	list = this->_staticStart;
	if (index == 0) {
		this->_staticStart->el->clearObject(win);
		delete this->_staticStart->el;
		this->_staticStart = this->_staticStart->next;
		delete list;
	} else {
		while (list && i < index - 1) {
			list = list->next;
			i++;
		}
		tmp = list;
		list = list->next;
		tmp->next = list->next;
		list->el->clearObject(win);
		delete list->el;
		delete list;
	}
	this->_nStatic--;
}

void	ControlListClass::pushBack(Enemy *obj) {
	t_enemies *tmp;

	tmp = this->_enemiesStart;
	if (!this->_enemiesStart) {
		this->_enemiesStart = new t_enemies;
		this->_enemiesStart->el = obj;
		this->_enemiesStart->next = NULL;
		this->_nEnemy++;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new t_enemies;
	tmp->next->el = obj;
	tmp->next->next = NULL;
	this->_nEnemy++;
}

void	ControlListClass::pushBack(StaticObject *obj) {
	t_static *tmp;

	tmp = this->_staticStart;
	if (!this->_staticStart) {
		this->_staticStart = new t_static;
		this->_staticStart->el = obj;
		this->_staticStart->next = NULL;
		this->_nStatic++;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new t_static;
	tmp->next->el = obj;
	tmp->next->next = NULL;
	this->_nStatic++;
}

void 	ControlListClass::clearAll(WINDOW *win) {
	this->_clearAllEnemies(win);
	this->_clearAllStatics(win);
}

void	ControlListClass::_clearAllEnemies(WINDOW *win) {
	t_enemies	*tmp;
	t_enemies	*list;

	list = this->_enemiesStart;
	while (list){
		tmp = list;
		list = list->next;
		tmp->el->clearObject(win);
		delete tmp->el;
		delete tmp;
		this->_nEnemy--;
	}
}

void	ControlListClass::_clearAllStatics(WINDOW *win) {
	t_static	*tmp;
	t_static	*list;

	list = this->_staticStart;
	while (list){
		tmp = list;
		list = list->next;
		tmp->el->clearObject(win);
		delete tmp->el;
		delete tmp;
		this->_nStatic--;
	}
}

void 	ControlListClass::drawAll(WINDOW *win) {
	t_enemies	*list_e;
	t_static	*list_s;

	list_e = this->_enemiesStart;
	while (list_e) {
		list_e->el->draw(win);
		list_e = list_e->next;
	}
	list_s = this->_staticStart;
	while (list_s) {
		list_s->el->draw(win);
		list_s = list_s->next;
	}
}

bool	ControlListClass::CheckCollisionForList(WINDOW *win,int *index_s, int *index_e, int x,
									 int y, std::string type) {
	t_enemies	*start;
	t_static	*begin;
	int			index = 0;

	start = this->_enemiesStart;
	begin = this->_staticStart;
	if (type == "Static") {
		while( begin) {
			if (*index_s < 0 || *index_s != index) {
				if (x == begin->el->getX() && y == begin->el->getY()) {
					if (*index_s >= 0 && *index_s > index)
						(*index_s)--;
					this->clearOne(index, "Static", win);
					return 1;
				}
			}
			begin = begin->next;
			index++;
		}
	} else {
		while (start) {
			if (*index_e < 0 || *index_e != index) {
				if (x == start->el->getX() && y == start->el->getY()) {
					if (*index_e >= 0 && *index_e > index)
						(*index_e)--;
					this->clearOne(index, "Enemy", win);
					return 1;
				}
			}
			start = start->next;
			index++;
		}
	}
	return 0;
}

int		ControlListClass::getNumStatic(void) {
	return this->_nStatic;
}

int		ControlListClass::getNumEnemies(void) {
	return this->_nEnemy;
}

void	ControlListClass::someAI(WINDOW *win, Player **players, int *n_of_players) {
	t_enemies	*now;
	int			index = 0;
	int			fake = -1;
	int			flag;
	Player 		*tmp;
	static unsigned int	times = 0;

	now = this->_enemiesStart;
	while (now) {
		flag = 0;
		if (!now->el->AI(players, *n_of_players))
		{
			now = now->next;
			this->clearOne(index, "Enemy", win);
			continue;
		}
		for (int i = 0; i < *n_of_players; i++) {
			if (players[i] && now->el->getX() == players[i]->getX() && now->el->getY() == players[i]->getY()) {
				players[i]->clearObject(win);
				(*n_of_players)--;
				if (i == 0) {
					tmp = players[0];
					players[0] = players[1];
					players[1] = tmp;
				}
				flag = 1;
				system("afplay ./sounds/boom.aiff&");
				now = now->next;
				this->clearOne(index,"Enemy", win);
				break;
			}
		}
		if (flag)
			continue;
		if ((this->CheckCollisionForList(win, &fake, &index, now->el->getX(), now->el->getY(), "Static")) || 
			(this->CheckCollisionForList(win, &fake, &index, now->el->getX(), now->el->getY(), "Enemy"))) {
				this->clearOne(index, "Enemy", win);
				now = now->next;
				continue;
		}
		times++;
		if (times % 4 == 0) {
			for (int i = 0; i < *n_of_players; i++) {
				if (players[i]) {
					if (now->el->getY() + 4 > players[i]->getY() && now->el->getY() - 4 < players[i]->getY()) {
						this->pushBack(now->el->shot());
					}
				}
			}
		}
		now = now->next;
		index++;
	}
}

void	ControlListClass::moveAllStatic(WINDOW *win, Player **players, int *n_of_players) {
	t_static	*now;
	int			index = 0;
	int			fake = -1;
	int			flag;
	Player 		*tmp;

	now = this->_staticStart;
	while(now) {
		flag = 0;
		if (!now->el->justFlyInSpace())
		{
			now = now->next;
			this->clearOne(index, "Static", win);
			continue;
		}
		for (int i = 0; i < *n_of_players; i++) {
			if (players[i] && now->el->getX() == players[i]->getX() && now->el->getY() == players[i]->getY()) {
				if (!(players[i]->takeDmg(now->el->getDamage()))) {
					players[i]->clearObject(win);
					(*n_of_players)--;
					if (i == 0) {
						tmp = players[0];
						players[0] = players[1];
						players[1] = tmp;
					}
				}
				flag = 1;
				system("afplay ./sounds/boom.aiff&");
				now = now->next;
				this->clearOne(index,"Static", win);
				break;
			}
		}
		if (flag)
			continue;
		if ((this->CheckCollisionForList(win, &index, &fake, now->el->getX(), now->el->getY(), "Static")) || 
			(this->CheckCollisionForList(win, &index, &fake, now->el->getX(), now->el->getY(), "Enemy"))) {
				this->clearOne(index, "Static", win);
				now = now->next;
				continue;
		}
		now = now->next;
		index++;
	}
}