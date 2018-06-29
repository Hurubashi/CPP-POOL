
#include "StaticObjectClass.hpp"

StaticObject::StaticObject(unsigned int x, unsigned int y, char dir) {
	this->_lastX = x;
	this->_lastY = y;
	this->_x = x;
	this->_y = y;
	this->_dir = dir;
	return ;
}

bool	StaticObject::justFlyInSpace(void) {
	return  this->move(this->_dir);
}

int		StaticObject::getDamage(void) {
	return this->_damage;
}

StaticObject::StaticObject(void) {
}

StaticObject::~StaticObject(void) {
}

StaticObject::StaticObject(const StaticObject &other) {
	*this = other;
}

StaticObject& StaticObject::operator= (const StaticObject &rhs) {
	this->_dir = rhs._dir;
	this->_damage = rhs._damage;
	return *this;
}