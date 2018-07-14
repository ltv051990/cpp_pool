#include "Enemy.class.hpp"
#include <ctime>
#include <cstdlib>

Enemy::Enemy(){
	int i = ((rand()) * std::time(nullptr)) % 98;
	if (i % 2 == 0)
		this->x = i; //((rand()) * std::time(nullptr)) % 98;
	else
		this->x = i + 1;
	this->y = ((rand()) * std::time(nullptr)) % 7;
}

Enemy::Enemy(Enemy const & src){
	*this = src;
}

Enemy::~Enemy(void){};

Enemy & Enemy::operator=(Enemy const & src)
{
	this->x = src.x;
	this->y = src.y;

	return *this;
}

bool Enemy::enemy_move()
{
	if (y < HEIGHT - 1) {
		y += 1;
	return true;
	}
	return false;
}

int Enemy::getX( void ) const {
	return this->x;
}

int Enemy::getY( void ) const {
	return this->y;
}

void Enemy::setX(int x){
	this->x = x;
}
void Enemy::setY(int y){
	this->y = y;
}