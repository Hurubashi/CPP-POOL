
#include "GameObjectClass.hpp"

void		GameObject::draw(WINDOW *win) {
	mvwaddch(win, this->_lastY, this->_lastX, ' ');
	mvwaddch(win, this->_y, this->_x, this->_symbol | COLOR_PAIR(this->_color) | A_BOLD);
	wrefresh(win);
}

void		GameObject::clearObject(WINDOW *win) {
	mvwaddch(win, this->_y, this->_x, ' ');
	mvwaddch(win, this->_lastY, this->_lastX, ' ');
}

bool		GameObject::move(char dir) {
	this->_lastX = this->_x;
	this->_lastY = this->_y;

	if (dir == 'U' && this->_y > 1)
		this->_y--;
	else if (dir == 'D' && this->_y + 2 < MAP_HEIGHT)
		this->_y++;
	else if (dir == 'L' && this->_x > 1)
		this->_x--;
	else if (dir == 'R' && this->_x + 2 < MAP_WIDTH - MENU_WIDTH)
		this->_x++;
	else
		return 0;
	return 1;
}

int			GameObject::getX(void) {
	return this->_x;
}

int			GameObject::getY(void) {
	return this->_y;
}

GameObject::GameObject(void) {
}

GameObject::~GameObject(void) {
}

GameObject::GameObject(const GameObject &other) {
	*this = other;
}

GameObject& GameObject::operator= (const GameObject &rhs) {
	this->_lastX = rhs._lastX;
	this->_lastY = rhs._lastY;
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_symbol = rhs._symbol;
	this->_color = rhs._color;
	return *this;
}