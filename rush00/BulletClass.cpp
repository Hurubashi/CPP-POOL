
#include "BulletClass.hpp"

Bullet::Bullet(unsigned int x, unsigned int y, char dir, int damage, int color) : StaticObject(x, y, dir) {
	this->_damage = damage;
	this->_symbol = '-';
	this->_color = color;
	system("afplay ./sounds/laser.wav&");
}

Bullet::Bullet(void) {
}

Bullet::~Bullet(void) {
}

Bullet::Bullet(const Bullet &other) {
	*this = other;
}

Bullet& Bullet::operator= (const Bullet &rhs) {
	return *this;
}