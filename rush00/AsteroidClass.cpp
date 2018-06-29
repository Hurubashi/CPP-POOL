
#include "AsteroidClass.hpp"

Asteroid::Asteroid(unsigned int x, unsigned int y, char dir, int damage) : StaticObject(x, y, dir) {
	this->_color = 3;
	this->_symbol = '@';
	this->_damage = 20;
}

Asteroid::Asteroid(void) {
}

Asteroid::~Asteroid(void) {
}

Asteroid::Asteroid(const Asteroid &other) {
	*this = other;
}

Asteroid& Asteroid::operator= (const Asteroid &rhs) {
	return *this;
}