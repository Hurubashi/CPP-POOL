
#include "PlayerClass.hpp"

Player::Player(int up, int right, int left, int down, int shot, int x, int y,
	int color, int bulletColor, int playerNum) {
	this->_upB = up;
	this->_rightB = right;
	this->_leftB = left;
	this->_downB = down;
	this->_shotB = shot;
	this->_shotDir = 'R';
	this->_hp = 100;
	this->_x = x;
	this->_y = y;
	this->_lastX = x;
	this->_lastY = y;
	this->_symbol = '>';
	this->_color = color;
	this->_myBulletColor = bulletColor;
	this->_playerNum = playerNum;
	return;
}

int		Player::KeyEvent(int ch) {
	if (ch != ERR){
		if (ch == this->_downB)
			ch = 'D';
		else if (ch == this->_upB) 
			ch = 'U';
		else if (ch == this->_leftB)
			ch = 'L';
		else if (ch == this->_rightB)
			ch = 'R';
		else if (ch == this->_shotB)
			return 2;
	} else {
		return 0;
	}
	if (!this->move(ch)) {
		this->_x = _lastX;
		this->_y = _lastY;
		return 0;
	}
	return 1;
}

int Player::getPlayerNb(void) {
	return (this->_playerNum);
}

Player::Player(void) {
}

Player::~Player(void) {
}

Player::Player(const Player &other) {
	*this = other;
}

Player& Player::operator= (const Player &rhs) {
	this->_upB = rhs._upB;
	this->_downB = rhs._downB;
	this->_leftB = rhs._rightB;
	this->_rightB = rhs._rightB;
	this->_shotB = rhs._shotB;
	this->_playerNum = rhs._playerNum;
	return *this;
}
