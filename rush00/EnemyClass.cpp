
#include "EnemyClass.hpp"

Enemy::Enemy(void) {
}

Enemy::~Enemy(void) {
}

Enemy::Enemy(const Enemy &other) {
    *this = other;
}

Enemy& Enemy::operator= (const Enemy &rhs) {
    return *this;
}

Enemy::Enemy(int x, int y, int color, int bulletColor) {
    this->_x = x;
    this->_y = y;
    this->_lastX = x;
    this->_lastY = y;
    this->_symbol = '<';
    this->_shotDir = 'L';
    this->_color = color;
    this->_myBulletColor = bulletColor;
    return;
}

bool    Enemy::AI(Player **players, int number_of_players) {
    Player  *low_hp = players[0];

    if (this->_x != this->_lastX) {
        for (int i = 0; i < number_of_players;i++) {
            if (players[i] && players[i]->getHp() < low_hp->getHp()) {
                low_hp = players[i];
            }
        }
        if (this->_y > low_hp->getY()) {
            return this->move('U');
        }
        else if (this->_y < low_hp->getY()) {
            return this->move('D');
        }
    }
    return this->move('L');
}