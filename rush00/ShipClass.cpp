
#include "ShipClass.hpp"

Bullet*				Ship::shot(void) {
	Bullet*			myBul;
	unsigned int	x = this->_x;
	unsigned int	y = this->_y;

	switch (this->_shotDir) {
		case 'U' : y--;
		case 'D' : y++;
		case 'L' : x--;
		case 'R' : x++;
	}
	myBul = new Bullet(x, y, this->_shotDir, 20, this->_myBulletColor);
	return myBul;
}

int 	Ship::getHp(void) {
		return this->_hp;
}

bool 	Ship::takeDmg(int num) {
	this->_hp -= num;
	if (this->_hp <= 0)
	{
		this->_hp = 0;
		return 0;
	}
	return 1;
}

Ship::Ship(void) {
}

Ship::~Ship(void) {
}

Ship::Ship(const Ship &other) {
	*this = other;
}

Ship& Ship::operator= (const Ship &rhs) {
	this->_shotDir = rhs._shotDir;
	this->_myBulletColor = rhs._myBulletColor;
	this->_hp = rhs._hp;
	return *this;
}